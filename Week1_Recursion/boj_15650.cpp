#include <iostream>
using namespace std;
int n, m, sel[8];
void perm(int cnt, int chk) {
    if(cnt == m) {
        for(int i = 0; i < m; ++i)
            cout << sel[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; ++i) {
        if(chk & (1 << i))
            continue;
        chk |= (1 << i);
        sel[cnt] = i;
        ++cnt;
        perm(cnt, chk);
        --cnt;
    }
}
int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    perm(0, 1);
}