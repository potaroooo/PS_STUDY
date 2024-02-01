#include <iostream>
using namespace std;
constexpr long long N = 1'000'001;
typedef long long ll;

ll query(int node, int left, int right, int st, int ed);
ll update(int node, int left, int right, int idx);

int n; 
ll sgt[(N << 2LL) + 1];

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    ll ans = 0, num;
    for(int i = 0; i < n; ++i) {
        cin >> num;
        --num;
        ans += (num - query(1, 1, n, 1, num));
        update(1, 1, n, num + 1);
    }
    cout << ans << '\n';
}

ll update(int node, int left, int right, int idx) {
    if(idx < left || idx > right) return sgt[node];
    if(left == right) return ++sgt[node];
    int mid = (left + right) / 2;
    return sgt[node] =
    update(node * 2, left, mid, idx) +
    update(node * 2 + 1, mid + 1, right, idx);
}

ll query(int node, int left, int right, int st, int ed) {
    if(left > ed || right < st) return 0;
    if(st <= left && right <= ed) return sgt[node];
    int mid = (left + right) / 2;
    return 
    query(node * 2, left, mid, st, ed) +
    query(node * 2 + 1, mid + 1, right, st, ed);
}