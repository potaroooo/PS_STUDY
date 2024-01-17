#include <iostream>
using namespace std;
constexpr int MX = 1'000'001;

int n, m, p[MX], r[MX];

int get_p(int x) {
    if(p[x] == x) return x;
    return p[x] = get_p(p[x]);
}

void uni(int x, int y) {
    x = get_p(x),
    y = get_p(y);
    if(x == y)
        return;
    if(r[x] >= r[y]) {
        p[y] = x;
        ++r[x];
    }
    else {
        p[x] = y;
        ++r[y];
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        p[i] = i;
    
    for(int i = 1, c, s, e; i <= m; ++i) {
        cin >> c >> s >> e;
        if(!c) {
            uni(s, e);
        }
        else {
            if(get_p(s) == get_p(e))
                cout << "yes\n";
            else 
                cout << "no\n";
        }
    }
}