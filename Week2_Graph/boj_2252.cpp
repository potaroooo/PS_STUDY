#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;
int n, m, cnt[32001];
vector<int> g[32001];
queue<int> q;
void run() {
    while(q.size()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for(int &nxt : g[cur]) {
            if(cnt[nxt] == INF) continue;
            --cnt[nxt];
            if(cnt[nxt] == 0) {
                q.push(nxt);
                cnt[nxt] = INF;
            }
        }
    }
}
int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int st, ed;
        cin >> st >> ed;
        ++cnt[ed];
        g[st].push_back(ed);
    }
    for(int i = 1; i <= n; ++i)
        if(!cnt[i]) {
            q.push(i);
            cnt[i] = INF;
        }
    run();
}