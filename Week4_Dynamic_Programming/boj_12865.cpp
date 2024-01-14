#include <iostream>
using namespace std;
constexpr int MX = 100'000;

int n, k, dp[MX + 1];

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> k;
    for(int i = 1, cw, cv; i <= n; ++i) {
        cin >> cw >> cv;
        for(int j = k; j >= 1; --j) {
            if(cw > j) continue;
            dp[j] = dp[j] > dp[j - cw] + cv ? dp[j] : dp[j - cw] + cv;
        }
    }
    cout << dp[k];
}