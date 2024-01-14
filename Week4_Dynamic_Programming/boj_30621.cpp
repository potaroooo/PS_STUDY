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
        int border = a[i].t - a[i].b, index = 0;
        dp[i] = a[i].c > dp[i - 1] ? a[i].c : dp[i - 1];
        for(int left = 1, right = i, mid = (i + 1) / 2; left <= right; mid = (left + right) / 2) {
            if(a[mid].t >= border) {
                right = mid - 1;                
            }
            else {
                left = mid + 1;
                index = mid;
            }
        }
        dp[i] = dp[i] > dp[index] + a[i].c ? dp[i] : dp[index] + a[i].c;
        ans = dp[i] > ans ? dp[i] : ans;
    }
    cout << ans << '\n';
}