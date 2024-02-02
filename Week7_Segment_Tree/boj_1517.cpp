#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N = 500'001;
typedef long long ll;
typedef pair<int, int> pii;

int n, sgt[N * 4 + 1];
pii arr[N];

ll query(int node, int left, int right, int st, int ed) {
    if(st > right || ed < left) return 0LL;
    if(st <= left && right <= ed) return sgt[node];
    int mid = (left + right) / 2;
    return
    query(node * 2, left, mid, st, ed) +
    query(node * 2 + 1, mid + 1, right, st, ed);
}

ll update(int node, int left, int right, int index) {
    if(index < left || index > right) return sgt[node];
    if(left == right) return sgt[node] = 1LL;
    int mid = (left + right) / 2;
    return sgt[node] =
    update(node * 2, left, mid, index) +
    update(node * 2 + 1, mid + 1, right, index);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for(int i = 0, num; i < n; ++i) {
        cin >> num;
        arr[i] = {num, i};
    }
    sort(arr, arr + n);

    ll ans = 0LL;
    for(int i = 0, idx; i < n; ++i) {
        idx = arr[i].second;
        ans += query(1, 0, n - 1, idx + 1, n - 1);
        update(1, 0, n - 1, idx);
    }
    cout << ans;
}