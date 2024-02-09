#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr int MX = 100'000;

typedef struct edge {
    int st, ed, weight;
} edge;

int N, M, tree[MX + 1], rnk[MX + 1];
edge v[MX * 10];

int find(int x) {
    if(tree[x] == x) return x;
    return tree[x] = find(tree[x]);
}

bool uni(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return false;
    if(rnk[x] >= rnk[y]) {
        ++rnk[x];
        tree[y] = x;
    }
    else {
        ++rnk[y];
        tree[x] = y;
    }
    return true;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> N >> M;
    if(N == 2) {
        cout << "0";
        return 0;
    }
    for(int i = 1; i <= N; ++i) {
        tree[i] = i, rnk[i] = 1;
    }
    for(int i = 0, A, B, C; i < M; ++i) {
        cin >> A >> B >> C;
        v[i] = {A, B, C};
    }
    sort(v, v + M, [](const edge& a, const edge& b) {
        return a.weight < b.weight;
    });
    for(int i = 0, cnt = 0, sum = 0; i < M; ++i) {
        if(cnt == N - 2) {
            cout << sum;
            return 0;
        }
        edge &cur = v[i];
        int st = cur.st, ed = cur.ed, weight = cur.weight;
        if(uni(st, ed)) {
            ++cnt;
            sum += weight;
        }
    }
}