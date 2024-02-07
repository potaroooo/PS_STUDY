#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
constexpr ll PINF = 9'876'543'210;
constexpr ll NINF = -PINF;
constexpr int MX_N = 100'000;
typedef struct node {
    ll dif = NINF,
    max = NINF,
    min = PINF;
} nd;

int N, Q, a[MX_N + 1];
nd sgt[MX_N * 4 + 5];

nd init(int node, int left, int right) {
    if(left == right)
        return sgt[node] = {
            0,
            a[left],
            a[left]
        };
    int mid = (left + right) / 2;
    nd l = init(node * 2, left, mid),
    r = init(node * 2 + 1, mid + 1, right);
    return sgt[node] = {
        max(r.max - l.min, max(r.dif, l.dif)),
        max(l.max, r.max),
        min(l.min, r.min)
    };
}

void update(int node, int left, int right, int index) {
    if(index < left || index > right) return;
    if(left == right && left == index) {
        sgt[node] = {
            0,
            a[left],
            a[left]
        };
        return;
    }
    int mid = (left + right) / 2;
    if(index <= mid)
        update(node * 2, left, mid, index);
    else
        update(node * 2 + 1, mid + 1, right, index);
    nd l = sgt[node * 2], r = sgt[node * 2 + 1];
    sgt[node] = {
        max(r.max - l.min, max(r.dif, l.dif)),
        max(l.max, r.max),
        min(l.min, r.min)
    };
}

nd query(int node, int left, int right, int st, int ed) {
    if(st > right || ed < left) return nd{};
    if(st <= left && right <= ed) return sgt[node];
    int mid = (left + right) / 2;
    nd l = query(node * 2, left, mid, st, ed),
    r = query(node * 2 + 1, mid + 1, right, st, ed);
    return {
        max(r.max - l.min, max(l.dif, r.dif)),
        max(l.max, r.max),
        min(l.min, r.min)
    };
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> N;
    for(int i = 1; i <= N; cin >> a[i++]);
    init(1, 1, N);
    cin >> Q;
    while(Q--) {
        int t, s, e;
        cin >> t >> s >> e;
        if(t == 1) {
            a[s] = e;
            update(1, 1, N, s);
        }
        else cout << query(1, 1, N, s, e).dif << '\n';
    }
}
