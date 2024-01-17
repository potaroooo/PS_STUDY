#include <iostream>
#include <vector>
#include <queue>
#define DEBUG
#define node first
#define dist second
constexpr int V = 10'000;

using namespace std;
typedef pair<int, int> pii;

int v, e;
vector<pii> grp[V + 1];
bool visit[V + 1];
priority_queue<pii> pq;

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> v >> e;
    for(int i = 1, a, b, c; i <= e; ++i) {
        cin >> a >> b >> c;
        grp[a].push_back({b, c});
        grp[b].push_back({a, c});
    }

    int dist = 0;
    visit[1] = true;
    for(const pii &init : grp[1]) {
        pq.push({-init.dist, init.node});
    }
    while(pq.size()) {
        pii cur = pq.top();
        pq.pop();
        if(visit[cur.second]) continue;
        visit[cur.second] = true;
        dist += -cur.first;
        for(const pii &nxt : grp[cur.second]) {
            pq.push({-nxt.dist, nxt.node});
        }
    }
    cout << dist;
}