#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;

typedef pair<int, int> pii;

constexpr int MX = 10'001;
int n, m, st, ed;
bool visit[MX];
vector<pii> g[MX];

int run(int val) {
    queue<int> q;
    visit[st] = true;
    q.push(st);
    while(q.size()) {
        int cur = q.front();
        q.pop();
        if(cur == ed) break;
        if(g[cur].empty()) continue;
        for(const pii &edge : g[cur]) {
            int nxt = edge.first, limit = edge.second;
            if(limit < val || visit[nxt]) continue;
            visit[nxt] = true;
            q.push(nxt);
        }
    }
    return visit[ed];
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int s, e, w;
        cin >> s >> e >> w;
        g[s].push_back({e, w});
        g[e].push_back({s, w});
    }
    cin >> st >> ed;
    int left = 0, mid, right = 1'000'000'000, ans = 0;
    while(left <= right) {
            mid = (left + right) / 2;
            if(run(mid)) {
                if(mid > ans) ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
            memset(visit, false, sizeof(bool) * (n + 1));
    }
    cout << ans;
}