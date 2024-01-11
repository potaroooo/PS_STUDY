#include <iostream>
// #define DEBUG
using namespace std;

int n, k, dp[10'001];

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> k;
    for(int i = 1, val; i <= n; ++i) {
        cin >> val;
        if(val > k) continue;
        ++dp[val];
        for(int j = val + 1; j <= k; ++j) {
            dp[j] += dp[j - val];
        }
        #ifdef DEBUG 
        cout << val << '\n';
        for(int j = 1; j <= k; ++j) {
            cout << dp[j] << ' ';
        }
        cout << '\n';
        #endif
    }
    
    cout << dp[k];
}