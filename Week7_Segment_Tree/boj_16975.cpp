#include <iostream>
#include <cmath>
#define DEBUG
using namespace std;
constexpr int N = 100'001;
typedef long long ll;

int n, m, a[N];
ll sgt[(N << 2LL) + 1LL];

void update(int node, int left, int right, int index, int dif) {
    if(left == index && right == index) {
        sgt[node] += dif;
        return;
    }
    if(left <= index && index <= right) {
        int mid = (left + right) / 2;
        update(node * 2, left, mid, index, dif);
        update(node * 2 + 1, mid + 1, right, index, dif);
        sgt[node] = sgt[node * 2] + sgt[node * 2 + 1];
        return;
    }
}

ll query(int node, int left, int right, int st, int ed) {
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

    cin >> n;
    for(int i = 0; i < n; cin >> a[i++]);

    cin >> m;
    for(int i = 1, cmd, st, ed; i <= m; ++i) {
        cin >> cmd >> st;
        if(cmd & 1) {
            ll k;
            cin >> ed >> k;
            --st, --ed;
            update(1, 0, n - 1, st, k);
            update(1, 0, n - 1, ed + 1, -k);
        }
        else {
            --st;
            #ifdef DEBUG
            // cout << "answer : ";
            #endif
            cout << query(1, 0, n - 1, 0, st) + a[st] << '\n';
        }
    }
}