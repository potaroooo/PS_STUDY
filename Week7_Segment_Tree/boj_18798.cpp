#include <iostream>
// #define DEBUG
using namespace std;
constexpr int MX_N = 250'000;

int N, M, K, A[MX_N + 1], bit[MX_N * 4 + 10], sgt[MX_N * 4 + 10];

void update_sgt(int node, int left, int right, int index, int count) {
    if(index < left || index > right) return;
    if(left == right) {
        sgt[node] += count;
        return;
    }
    int mid = (left + right) / 2;
    update_sgt(node * 2, left, mid, index, count);
    update_sgt(node * 2 + 1, mid + 1, right, index, count);
    sgt[node] = sgt[node * 2] + sgt[node * 2 + 1];
}

int init(int node, int left, int right) {
    if(left == right) {
        return bit[node] = A[left];
    }
    int mid = (left + right) / 2;
    return bit[node] =
    init(node * 2, left, mid) &
    init(node * 2 + 1, mid + 1, right);
}

void update(int node, int left, int right, int st, int ed, int val) {
    if(left > ed || right < st) return;
    if(left == right) {
        if(bit[node] == K) update_sgt(1, 1, N, left, -1);
        bit[node] |= val;
        if(bit[node] == K) update_sgt(1, 1, N, left, 1);
        #ifdef DEBUG
        cout << "leaf_updated\n";
        #endif
        return;
    }
    int mid = (left + right) / 2;
    #ifdef DEBUG
        cout << val << ' ';
        cout << (int)(sgt[node * 2] & val) << ' ';
        cout << (int)(sgt[node * 2 + 1] & val) << '\n';
    #endif
    if((bit[node * 2] & val) != val)
        update(node * 2, left, mid, st, ed, val);
    if((bit[node * 2 + 1] & val) != val)
        update(node * 2 + 1, mid + 1, right, st, ed, val);
    bit[node] = bit[node * 2] & bit[node * 2 + 1];
}

int query(int node, int left, int right, int st, int ed) {
    if(st > right || ed < left) return 0;
    if(st <= left && right <= ed) return sgt[node];
    int mid = (left + right) / 2;
    return 
        query(node * 2, left, mid, st, ed) +
        query(node * 2 + 1, mid + 1, right, st, ed);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> N >> K;
    for(int i = 1; i <= N; ++i) {
        cin >> A[i];
        if(A[i] == K) update_sgt(1, 1, N, i, 1);
    }
    init(1, 1, N);
    cin >> M;
    while(M--) {
        int a, b, c, d;
        cin >> a >> b >> c;
        if(a == 1) {
            cin >> d;
            #ifdef DEBUG
            cout << "before update\n";
            for(int i = b; i <= c; ++i) {
                cout << A[i] << ' ';
            }
            cout << '\n';
            #endif 
            update(1, 1, N, b, c, d);
            #ifdef DEBUG
            cout << "after update\n";
            for(int i = b; i <= c; ++i) {
                cout << A[i] << ' ';
            }
            cout << '\n';
            #endif 
        }
        else {
            #ifdef DEBUG
            int cnt = 0;
            for(int i = b; i <= c; ++i) {
                if(A[i] == K) ++cnt;
            }
            cout << "real count : " << cnt;
            cout << '\n';
            #endif 
            cout << query(1, 1, N, b, c) << '\n';
        }
    }
}