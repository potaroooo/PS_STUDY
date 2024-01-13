#include <iostream>
#include <algorithm>
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
        return a.t < b.t;
    });

    dp[1] = a[1].c;
    for(int i = 2; i <= n; ++i) {
        int idx = 0, lim = a[i].t - a[i].b;
        for(int left = 1, right = i, mid = (i + 1) / 2; left <= right; mid = (left + right) / 2) {
            if(a[mid].t >= lim) {
                right = mid - 1;
            }
            else {
                idx = mid;
                left = mid + 1;
            }
        }
        dp[i] = dp[idx] + a[i].c;
        if(ans < dp[i]) ans = dp[i];
    }

    cout << ans << '\n';
}