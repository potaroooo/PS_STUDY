#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
constexpr int MX = 9;
constexpr int INF = MX * 1'000 + 1;

int N, M, H[MX];
bool not_prime[INF]{true, true};
map<int, int> ans;

void dfs(int idx = -1, int cnt = 0, int sum = 0) {
    if(cnt == M) {
        if(!not_prime[sum]) ans[sum] = sum;
        return;
    }
    for(int i = idx + 1; i < N; ++i) {
        dfs(i, cnt + 1, sum + H[i]);
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> N >> M;
    for(int i = 0; i < N; cin >> H[i++]);
    for(int i = 2; i <= INF; ++i) {
        if(not_prime[i]) continue;
        for(int j = i << 1; j <= INF; j += i) {
            if(not_prime[j]) continue;
            not_prime[j] = true;
        }
    }
    dfs();
    if(ans.size()) {
        for(auto it = ans.begin(); it != ans.end(); ++it) {
            cout << it->second << ' ';
        }
    }
    else cout << "-1\n";
}