#include <iostream>
#define DEBUG
using namespace std;
constexpr int MX = 200'000;
typedef long long ll;

int N, M, root[MX + 1];
ll cnt[MX + 1];

int find(int x) {
    if(root[x] == x) return x;
    return root[x] = find(root[x]);
}

void join(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return;
    cnt[x] += cnt[y];
    root[y] = x;
    return;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i)
        root[i] = i, cnt[i] = 1;
    ll ans = N;
    while(M--) {
        int a, b;
        cin >> a >> b;
        a = find(a), b = find(b);
        if(a != b) {
            ll ksa = cnt[a], ksb = cnt[b];
            ksa = ksa * (ksa - 1) / 2,
            ksb = ksb * (ksb - 1) / 2;
            ans -= (ksa + ksb);
            join(a, b);
            ll ksj = cnt[a];
            ksj = ksj * (ksj - 1) / 2;
            ans += ksj;       
        }
        cout << ans << '\n';
    }
}