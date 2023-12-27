#include <iostream>
#include <vector>
using namespace std;
int n;
bool chk[300001];
vector<int> v[300001];
void run(int node) {
    for(int nxt : v[node]) {
        if(chk[nxt]) continue;
        chk[nxt] = true;
        run(nxt);
    }
}
int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n - 2; ++i) {
        int st, ed;
        cin >> st >> ed;
        v[st].push_back(ed);
        v[ed].push_back(st);
    }
    for(int i = 1; i <= n; ++i) {
        if(!chk[i]) {
            cout << i << ' ';
            chk[i] = true;
            run(i);
        }
    }
}