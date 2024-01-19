#include <iostream>
#include <algorithm>
#define DEBUG
using namespace std;
constexpr int N = 2'000;
constexpr int M = 5'000;

typedef struct edge {
    int u, v, w;
} edge;

int n, m, s, p[N + 1], r[N + 1], ans;
edge graph[M + 1];

int find_p(int x) {
    if(p[x] == x) return x;
    return p[x] = find_p(p[x]);
}

bool join(int x, int y) {
    x = find_p(x), y = find_p(y);
    if(x == y) return false;
    if(r[x] >= r[y]) {
        p[y] = x;
        ++r[x];
    }
    else {
        p[x] = y;
        ++r[y];
    }
    return true;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m >> s;
    for(int i = 1; i <= m; ++i) {
        cin >> graph[i].u >> graph[i].v >> graph[i].w;
    }
    sort(graph + 1, graph + 1 + m, [](const edge& a, const edge& b) {
        return a.w < b.w;
    });
    for(int i = 1, j; i <= n; ++i) {
        cin >> j;
        p[i] = i;
    }

    for(int i = 1, cnt = 0; i <= m; ++i) {
        int u = graph[i].u, v = graph[i].v, w = graph[i].w;
        if(join(u, v)) {
            ans += w;
            ++cnt;
        }
        if(cnt == n - 1) break;
    }
    cout << ans;
}