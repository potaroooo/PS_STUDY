#include <iostream>
#include <algorithm>
// #define DEBUG
using namespace std;
constexpr int MX = 100'000;

typedef struct ugh{
    int t, b, c;
} ugh;

int n;
long long dp[MX + 1], ans;
ugh a[MX + 1];

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i].t;
    }
    for(int i = 1; i <= n; ++i) {
        cin >> a[i].b;
    }
    for(int i = 1; i <= n; ++i) {
        cin >> a[i].c;
    }
    sort(a + 1, a + 1 + n, [](const ugh &a, const ugh &b) {
        return a.t < b.t; // 발성 가능 시간의 오름차순으로 정렬
    });

    dp[1] = a[1].c;
    for(int i = 2; i <= n; ++i) {
        int lim = a[i].t - a[i].b; // lim 이후부터 발성하면 안됨
        dp[i] = a[i].c;
        for(int left = 0, right = i - 1, mid = (i - 1) / 2; left <= right; mid = (left + right) / 2) {
            if(a[mid].t >= lim) { // lim 이후에 발성한 경우이므로 새롭게 발성할 수 없음, 더 작은 mid값 탐색
                right = mid - 1;
            }
            else { // 발성할 수 있는 경우 해당하는 경우 중 dp[i]를 가장 크게 갱신할 수 있는 값을 찾아감
                left = mid + 1;
                #ifdef DEBUG
                    cout << "i : " << i << " lim : " << lim << " mid : " << mid << " dp[mid] : " << dp[mid] << '\n';
                #endif
                if(dp[i] < dp[mid] + a[i].c)
                    dp[i] = dp[mid] + a[i].c;
            }
        }
        if(ans < dp[i]) ans = dp[i];
        #ifdef DEBUG
        cout << "i : " << i << ", dp[i] : " << dp[i] << '\n';
        #endif
    }
    cout << ans << '\n';
}