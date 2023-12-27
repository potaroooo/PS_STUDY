#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int n, r1, r2, ans;
vector<pii> v[100001];
void run(int node, int sum, int mx, int prv) {
    if(node == r2) {
        ans = sum - mx;
        return;
    }
    for(auto &nxt : v[node]) {
        if(nxt.first == prv)
            continue;
        int tmx = mx > nxt.second ?
            mx : nxt.second;
        run(nxt.first, sum + nxt.second, tmx, node);
    }
}
int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> r1 >> r2;
    for(int i = 1; i < n; ++i) {
        int st, ed, di;
        cin >> st >> ed >> di;
        v[st].push_back({ed, di});
        v[ed].push_back({st, di});
    }
    run(r1, 0, 0, 0);
    cout << ans;
}