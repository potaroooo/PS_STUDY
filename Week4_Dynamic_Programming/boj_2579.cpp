#include <iostream>
using namespace std;

int n, arr[301], dp[302];

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> arr[i];
    
    dp[1] = arr[1], dp[2] = dp[1] + arr[2];
    for(int i = 3; i <= n; ++i) {
        dp[i] = arr[i] + (dp[i - 2] > dp[i - 3] + arr[i - 1] ? dp[i - 2] : dp[i - 3] + arr[i - 1]);
    }
    
    cout << dp[n];
}
