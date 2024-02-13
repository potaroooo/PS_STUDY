#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define DEBUG
using namespace std;
constexpr int MX = 500'000;

int n, m, cnt[MX + 1];
double c[MX + 1], dp[MX + 1];
vector<int> edge[MX + 1];

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cout << fixed;
    cout.precision(7);
    cin >> n >> m;
    for(int i = 0; i < n; cin >> c[i++]);
    while(m--) {
        int a, b;
        cin >> a >> b;
        ++cnt[a];
        edge[b].push_back(a);
    }
    queue<int> q;
    for(int i = 0; i < n; ++i) {
        if(!cnt[i]) {
            dp[i] = c[i];
            q.push(i);
        }
    }
    while(q.size()) {
        int cur = q.front();
        q.pop();
        for(const int &nxt : edge[cur]) {
            --cnt[nxt];
            dp[nxt] = max(dp[cur], dp[nxt]);
            dp[nxt] = max(dp[nxt], c[nxt] + dp[cur] / 2.0);
            if(!cnt[nxt]) q.push(nxt);
        }
    }
    cout << dp[0];
}