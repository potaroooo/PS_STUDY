#include <iostream>
#define w first
#define v second
using namespace std;

constexpr int MX = 100'000;

typedef pair<int, int> pii;

int n, k, dp[MX + 1];
pii a[100 + 1];

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i].w >> a[i].v;
    }

    for(int i = 1; i <= n; ++i) {
        int cw = a[i].w, cv = a[i].v;
        for(int j = k; j >= 1; --j) {
            if(cw > j) continue;
            dp[j] = dp[j] > dp[j - cw] + cv ? dp[j] : dp[j - cw] + cv;
        }
    }

    cout << dp[k];
}