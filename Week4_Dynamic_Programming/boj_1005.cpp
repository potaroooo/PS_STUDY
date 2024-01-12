#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int MX = 100'000;

int tc, n, k, w, d[1'001], cnt[1'001], dp[1'001];
vector<int> g[1'001];

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> tc;
    while(tc > 0) {
        --tc;
        cin >> n >> k;
        for(int i = 1; i <= n; ++i) {
            dp[i] = -1, cnt[i] = 0;
            cin >> d[i];
            g[i].clear();
        }

        for(int i = 1, s, e; i <= k; ++i) {
            cin >> s >> e;
            ++cnt[e];
            g[s].push_back(e);
        }
        cin >> w;

        queue<int> q;
        for(int i = 1; i <= n; ++i) {
            if(!cnt[i]) {
                q.push(i);
                dp[i] = d[i];
            }
        }

        while(q.size()) {
            int cur = q.front();
            q.pop();

            for(int nxt : g[cur]) {
                --cnt[nxt];
                dp[nxt] = dp[nxt] > dp[cur] + d[nxt] ? dp[nxt] : dp[cur] + d[nxt];
                if(!cnt[nxt])
                    q.push(nxt);
            }
        }

        cout << dp[w] << '\n';
    }
}