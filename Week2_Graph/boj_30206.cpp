#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
constexpr int MAX = 200'000;
constexpr int MOD = 1'000'000'007LL;

typedef pair<int, int> pii;
typedef long long ll;

int n, m;
bool chk[MAX + 1]{true};
ll cnt[MAX + 1];
vector<int> grp[MAX + 1];

ll run() {
    int mx_lvl = 0;
    queue<pii> q;
    chk[1] = true;
    q.push({1, 0});
    while(q.size()) {
        int cur = q.front().first,
        lvl = q.front().second;
        ++cnt[lvl];
        if(lvl > mx_lvl) mx_lvl = lvl;
        q.pop();
        for(const int &nxt : grp[cur]) {
            if(chk[nxt]) continue;
            chk[nxt] = true;
            q.push({nxt, lvl + 1});
        }
    }
    ll ans = 1LL;
    for(int lvl = 0; lvl <= mx_lvl; ++lvl) {
        ans = (ans *  (cnt[lvl] + 1)) % MOD;
    }
    return ans - 1;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1, st, ed; i <= m; ++i) {
        cin >> st >> ed;
        grp[st].push_back(ed);
        grp[ed].push_back(st);
    }

    cout << run();
}