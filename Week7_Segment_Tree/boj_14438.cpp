#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
constexpr int N = 100'002;
constexpr int INF = 2'100'000'000;

int n, m, a[N], tree[N * 4];

void update(int node, int left, int right, int index, int val);
int init(int node, int left, int right);
int query(int node, int left, int right, int st, int ed);

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; cin >> a[i++]);
    init(1, 0, n - 1);
    
    cin >> m;
    while(m--) {
        int q, s, e;
        cin >> q >> s >> e;
        if(q & 1) { // update
            update(1, 0, n - 1, s - 1, a[s - 1] = e);
        }
        else { // query
            cout << query(1, 0, n - 1, s - 1, e - 1) << '\n';
        }
    } 
}

int init(int node, int left, int right) {
    if(left == right)
        return tree[node] = a[left];
    int mid = (left + right) / 2;
    return tree[node] =
        min(init(node * 2, left, mid), init(node * 2 + 1, mid + 1, right));
}

void update(int node, int left, int right, int index, int val) {
    if(index < left || index > right) return;
    if(left == right) {
        tree[node] = val;
        return;
    }
    int mid = (left + right) / 2;
    update(node * 2, left, mid, index, val);
    update(node * 2 + 1, mid + 1, right, index, val);
    tree[node] = min(val, min(tree[node * 2], tree[node * 2 + 1]));
}

int query(int node, int left, int right, int st, int ed) {
    if(right < st || left > ed) return INF;
    if(st <= left && right <= ed) return tree[node];
    int mid = (left + right) / 2;
    return min(query(node * 2, left, mid, st, ed), query(node * 2 + 1, mid + 1, right, st, ed));
}