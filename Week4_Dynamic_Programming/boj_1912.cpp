#include <iostream>
using namespace std;
constexpr int MX = 100'000;

int n, a[MX + 1], dp[MX + 1], ans = -2'100'000'000;

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i) {
        dp[i] = a[i] > dp[i - 1] + a[i] ? a[i] : dp[i - 1] + a[i];
        if(dp[i] > ans) ans = dp[i];
    }
    cout << ans;
}