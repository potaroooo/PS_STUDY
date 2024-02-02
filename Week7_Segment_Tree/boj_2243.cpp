#include <iostream>
#define DEBUG
using namespace std;
constexpr int N = 1'000'000;

int n, sgt[(N << 2) + 11];

void update_candy(int node, int left, int right, int index, int count) {
    if(index < left || index > right) return;
    if(left == right) {
        sgt[node] += count;
        return;
    }
    int mid = (left + right) / 2;
    update_candy(node * 2, left, mid, index, count);
    update_candy(node * 2 + 1, mid + 1, right, index, count);
    sgt[node] = sgt[node * 2] + sgt[node * 2 + 1];
}

int get_candy(int node, int left, int right, int count) {
    if(left == right) return left; 
    int mid = (left + right) / 2;
    if(count <= sgt[node * 2]) return get_candy(node * 2, left, mid, count);
    else return get_candy(node * 2 + 1, mid + 1, right, count - sgt[node * 2]);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for(int a, b, c; n; --n) {
        cin >> a >> b;
        if(a & 1) {
            int ans = get_candy(1, 1, N, b);
            cout << ans << '\n';
            update_candy(1, 1, N, ans, -1);
        }
        else {
            cin >> c;
            update_candy(1, 1, N, b, c);
        }
    }
}