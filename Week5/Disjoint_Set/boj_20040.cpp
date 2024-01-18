#include <iostream>
using namespace std;
constexpr int N = 500'000;

int n, m, p[N + 1], h[N + 1];

int get_p(int x) {
    if(p[x] == x) return x;
    return p[x] = get_p(p[x]);
}

bool join(int x, int y) {
    x = get_p(x), y = get_p(y);
    if(x == y) return true; // 사이클 생성됨
    if(h[x] >= h[y]) {
        p[y] = x;
        ++h[x];
    }
    else {
        p[x] = y;
        ++h[y];
    }
    return false;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        p[i] = i, h[i] = 1;
    }

    for(int i = 1, st, ed; i <= m; ++i) {
        cin >> st >> ed;
        if(join(st, ed)) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
}