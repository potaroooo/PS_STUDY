#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, s;
vector<int> g[1001];
bool chk[1001];
void dfs(int node) {
    cout << node << ' ';
    for(int nxt : g[node]) {
        if(chk[nxt]) continue;
        chk[nxt] = true;
        dfs(nxt);
    }
}
void bfs(int node) {
    bool vst[1001]{};
    vst[node] = true;
    queue<int> q;
    q.push(node);
    while(q.size()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for(int nxt : g[cur]) {
            if(vst[nxt]) continue;
            vst[nxt] = true;
            q.push(nxt);
        }
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m >> s;
    for(int i = 1; i <= m; ++i) {
        int st, ed;
        cin >> st >> ed;
        g[st].push_back(ed);
        g[ed].push_back(st);
    }
    for(int i = 1; i <= n; ++i) {
        sort(g[i].begin(), g[i].end());
    }
    chk[s] = true;
    dfs(s);
    cout << '\n';
    bfs(s);
}