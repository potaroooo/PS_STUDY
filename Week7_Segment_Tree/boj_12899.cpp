#include <iostream>
using namespace std;
constexpr int MX = 2'000'000;

int N, sgt[MX * 4 + 10];

void update(int node, int left, int right, int num, int cnt) {
    if(num < left || num > right) return;
    if(left == right) {
        sgt[node] += cnt;
        return;
    }
    int mid = (left + right) / 2;
    update(node * 2, left, mid, num, cnt);
    update(node * 2 + 1, mid + 1, right, num, cnt);
    sgt[node] = sgt[node * 2] + sgt[node * 2 + 1];
}

int query(int node, int left, int right, int count) {
    if(left == right) return left;
    int mid = (left + right) / 2;
    if(count <= sgt[node * 2])
        return query(node * 2, left, mid, count);
    else return query(node * 2 + 1, mid + 1, right, count - sgt[node * 2]);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> N;
    while(N--) {
        int T, X;
        cin >> T >> X;
        if(T & 1) update(1, 1, MX, X, 1);
        else {
            int ans = query(1, 1, MX, X);
            cout << ans << '\n';
            update(1, 1, MX, ans, -1);
        }
    }
}