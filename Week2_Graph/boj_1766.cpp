#include <iostream>
#include <queue>
#include <vector>
using namespace std;
priority_queue<int> pq;
int n, m, cnt[32001];
vector<int> g[32001];
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
    for(int i = 1; i <= n; ++i) {
        if(!cnt[i]) pq.push(-i);
    }
    while(pq.size()) {
        int cur = -pq.top();
        pq.pop();
        cout << cur << ' ';
        for(int &nxt : g[cur]) {
            --cnt[nxt];
            if(!cnt[nxt]) pq.push(-nxt);
        }
    }
}