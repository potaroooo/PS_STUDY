#include <iostream>
#include <vector>
// #define DEBUG
using namespace std;
constexpr int MX = 200'000;
typedef struct query {
    int x = 0, a = 0, b = 0;
} qr;

int N, Q, parent[MX + 1]{0, 1}, root[MX + 1]{0, 1}, tier[MX + 1];
vector<qr> q;
vector<bool> r;

int find_root(int node) {
    if(root[node] == node) return node;
    return root[node] = find_root(root[node]);
}

void join(int node1, int node2) {
    node1 = find_root(node1),
    node2 = find_root(node2);
    if(node1 == node2) return;
    if(tier[node1] >= tier[node2]) {
        ++tier[node1];
        root[node2] = node1;
    }
    else {
        ++tier[node2];
        root[node1] = node2;
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> N >> Q;
    for(int i = 2; i <= N; ++i) {
        cin >> parent[i];
        root[i] = i;
    }
    Q = N - 1 + Q;
    q.resize(Q);
    for(int i = 0; i < Q; ++i) {
        qr& qq = q[i];
        cin >> qq.x >> qq.a;
        if(qq.x) {
            cin >> qq.b;
        }
    }
    #ifdef DEBUG
    cout << "query list : \n";
    for(const qr& qq : q) {
        cout << qq.x << ' ' << qq.a << ' ' << qq.b << '\n';
    }
    cout << "list end\n";
    #endif
    for(auto it = q.end() - 1; it >= q.begin(); --it) {
        const qr& qq = *it;
        #ifdef DEBUG
        cout << "current query : " << qq.x << ' ' << qq.a << ' ' << qq.b << '\n';
        #endif
        if(qq.x) {
            r.push_back(find_root(qq.a) == find_root(qq.b));
        }
        else {
            join(parent[qq.a], qq.a);
        }
    }
    for(auto it = r.end() - 1; it >= r.begin(); --it) {
        if(*it) cout << "YES\n";
        else cout << "NO\n";
    }
}