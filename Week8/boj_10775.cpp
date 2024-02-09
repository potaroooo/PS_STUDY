#include <iostream>
using namespace std;
constexpr int MX = 100'000;

int G, P, g[MX + 1], root[MX + 1];

int find(int x) {
    if(root[x] == x) return x;
    return root[x] = find(root[x]);
}

void uni(int x, int y) {    
    x = find(x), y = find(y);
    root[y] = x;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> G >> P;
    for(int i = 1, mx = G > P ? G : P; i <= mx; ++i) {
       if(i <= G) root[i] = i;
       if(i <= P) cin >> g[i];
    }
    for(int i = 1, ans = 0; i <= P; ++i) {
        int gate = find(g[i]);
        if(gate > 0) {
            ++ans;
            uni(gate - 1, gate);
        }
        else {
            cout << ans;
            return 0;
        }
        if(i == P) cout << ans;
    }
}