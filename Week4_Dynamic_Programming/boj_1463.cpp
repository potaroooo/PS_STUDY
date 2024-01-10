#include <iostream>
using namespace std;
constexpr int MX = 1'000'000;

int n, dp[MX + 1];

int main() {
    scanf("%d", &n);
    for(int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + 1;
        if(!(i % 2)) dp[i] = dp[i / 2] + 1 < dp[i] ? dp[i / 2] + 1 : dp[i];
        if(!(i % 3)) dp[i] = dp[i / 3] + 1 < dp[i] ? dp[i / 3] + 1 : dp[i];
    }
    printf("%d\n", dp[n]);
}