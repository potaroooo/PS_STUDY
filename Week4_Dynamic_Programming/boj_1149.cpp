#include <iostream>
#define DEBUG
using namespace std;
constexpr int MX = 1'000;

int n, dp[3][MX + 1];

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> dp[0][i] >> dp[1][i] >> dp[2][i];
    }

    for(int i = 2; i <= n; ++i) {
        dp[0][i] += (dp[1][i - 1] < dp[2][i - 1] ? dp[1][i - 1] : dp[2][i - 1]);
        dp[1][i] += (dp[0][i - 1] < dp[2][i - 1] ? dp[0][i - 1] : dp[2][i - 1]);
        dp[2][i] += (dp[0][i - 1] < dp[1][i - 1] ? dp[0][i - 1] : dp[1][i - 1]);
    }

    cout << (dp[0][n] < dp[1][n] ? (dp[0][n] < dp[2][n] ? dp[0][n] : dp[2][n]) : 
    (dp[1][n] < dp[2][n] ? dp[1][n] : dp[2][n]));
}