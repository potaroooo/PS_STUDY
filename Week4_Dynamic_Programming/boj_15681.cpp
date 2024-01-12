#include <iostream>
#include <vector>
constexpr int MX = 100'000;
using namespace std;

int n, r, q, dp[MX + 1];
vector<int> tree[MX + 1];

int run(int node, int prev) {
    int &ret = dp[node];
    if(ret == 0) {
        ret = 1;
        for(int next : tree[node]) {
            if(next == prev) continue;
            ret += run(next, node);
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> r >> q;
    for(int i = 1, s, e; i < n; ++i) {
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }

    run(r, -1);
    for(int i = 1, qq; i <= q; ++i) {
        cin >> qq;
        cout << dp[qq] << '\n';
    }
}