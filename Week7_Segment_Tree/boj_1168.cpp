#include <iostream>
using namespace std;
constexpr int MX = 100'000;

int N, K, sgt[MX * 4 + 10];

int init(int node = 1, int left = 1, int right = N) {
    if(left == right) return ++sgt[node];
    int mid = (left + right) / 2;
    return sgt[node] =
    init(node * 2, left, mid) +
    init(node * 2 + 1, mid + 1, right); 
}

int query(int node, int left, int right, int pos) {
    --sgt[node];
    if(left == right) return left;
    int mid = (left + right) / 2;
    if(pos <= sgt[node * 2]) return query(node * 2, left, mid, pos);
    return query(node * 2 + 1, mid + 1, right, pos - sgt[node * 2]);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> N >> K;
    init();
    int pos = 0;
    cout << '<';
    for(int i = 1; i < N; ++i) {
        pos += K;
        pos %= sgt[1];
        if(!pos) pos = sgt[1];
        int ans = query(1, 1, N, pos);
        cout << ans << ", ";
        --pos;
    }
    cout << query(1, 1, N, 1) << '>';
}