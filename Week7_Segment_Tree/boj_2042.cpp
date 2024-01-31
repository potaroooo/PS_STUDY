#include <iostream>
using namespace std;
constexpr int N = 1'000'000;
typedef long long ll;

int n, m, k;
ll arr[N + 1], tree[5 * N + 1];

ll init(int node, int left, int right) {
    if(left == right)
        return tree[node] = arr[left];
    int mid = (left + right) / 2;
    return tree[node] = init(node * 2, left, mid) +
    init(node * 2 + 1, mid + 1, right);
}

void update(int node, int index, long long dif, int left, int right) {
    if(left > index || right < index) return;
    tree[node] += dif;
    if(left == right) return;
    int mid = (left + right) / 2;
    update(node * 2, index, dif, left, mid);
    update(node * 2 + 1, index, dif, mid + 1, right);
}

ll query(int node, int st, int ed, int left, int right) {
    if(ed < left || st > right) return 0;
    if(st <= left && right <= ed)
        return tree[node];
    int mid = (left + right) / 2;
    return query(node * 2, st, ed, left, mid) +
    query(node * 2 + 1, st, ed, mid + 1, right);
}
 
int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m >> k;
    for(int i = 0; i < n; cin >> arr[i++]);
    init(1, 0, n - 1);
    for(int i = 1, lim = m + k, a, b; i <= lim; ++i) {
        ll c;
        cin >> a >> b >> c;
        if(a & 1) { // update
            ll dif = c - arr[b - 1];
            arr[b - 1] = c;
            update(1, b - 1, dif, 0, n - 1);
        }
        else { // query
            cout << query(1, b - 1, c - 1, 0, n - 1) << '\n';
        }
    }
}