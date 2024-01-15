#include <iostream>
// #define DEBUG
using namespace std;

int n, k, x; 
bool dp[81][16001];

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    
    cin >> n >> k >> x;
    for(int i = 1, a; i <= n; ++i) {
        cin >> a >> a;
        for(int j = k; j >= 1; --j) {
            for(int p = x * k; p >= a; --p) {
                dp[j][p] |= dp[j - 1][p - a];
            }
        }
        dp[1][a] = true;
    }

    int ans = 0;
    for(int i = 1; i <= k * x - 1; ++i) {
        if(dp[k][i]) {
            int cur = i * (k * x - i);
            if(cur > ans) ans = cur;
        }
    }
    cout << ans << '\n';
}