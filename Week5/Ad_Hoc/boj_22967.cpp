#include <iostream>
#include <vector>
#include <queue>
#define DEBUG
using namespace std;
constexpr int N = 300;

int n;
bool v[N + 1][N + 1];

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for(int i = 1, s, e; i <= n - 1; ++i) {
        cin >> s >> e;
        v[s][e] = true;
        v[e][s] = true;
    }

    int dia = 0;
    vector<pair<int, int>> ans;
    if((n - 1) * n / 2 - (n - 1) <= n - 1) { // 완전 그래프로 만들 수 있다
        for(int i = 1; i <= n; ++i) {
            for(int j = 1;  j <= n; ++j) {
                if(i == j || v[i][j] || v[j][i]) continue;
                v[i][j] = v[j][i] = true;
                ans.push_back({i, j});
            }
        }
        dia = 1;
    }
    else {
        for(int j = 1; j <= n; ++j) {
            if(j == 2 || v[2][j] || v[j][2]) continue;
            v[2][j] = v[j][2] = true;
            ans.push_back({2, j});
        }
        dia = 2;
    }
    cout << ans.size() << '\n';
    cout << dia << '\n';
    for(auto &pii : ans) {
        cout << pii.first << ' ' << pii.second << '\n';
    }
}