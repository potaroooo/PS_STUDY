#include <iostream>
#include <queue>
#include <cmath>
#define y first
#define x second
using namespace std;
typedef pair<int, int> pii;
int tc, n;
pii g[105];
bool chk[105];
int get_dif(pii &a, pii &b) {
    return abs(a.y - b.y) +
        abs(a.x - b.x);
}
void go() {
    chk[1] = true;
    queue<pii> q;
    q.push(g[1]);
    while(q.size()) {
        pii cur = q.front();
        q.pop();
        if(get_dif(cur, g[n + 2]) <= 1000) {
            cout << "happy\n";
            return;
        }
        for(int i = 2; i <= n + 1; ++i) {
            if(chk[i] || get_dif(cur, g[i]) > 1000)
                continue;
            chk[i] = true;
            q.push(g[i]);
        }
    }
    cout << "sad\n";
}
int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> tc;
    while(tc > 0) {
        --tc;
        cin >> n;
        for(int i = 1; i <= n + 2; ++i) {
            cin >> g[i].x >> g[i].y;
            chk[i] = false;
        }
        go();
    }
}