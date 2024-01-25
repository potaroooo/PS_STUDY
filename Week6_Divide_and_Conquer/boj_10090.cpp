#include <iostream>
using namespace std;
constexpr int N = 1'000'000;

int n, a[N + 1], b[N + 1];

int count_inversion(int left, int right) {
    if(left >= right) return 0;
    int mid = (left + right) / 2, ans = 0;
    ans += count_inversion(left, mid);
    ans += count_inversion(mid + 1, right);
    int idx = 1, count = 0, l = left, r = mid + 1;
    while(l <= mid && r <= right) {
        if(a[l] < a[r]) {
            ans += count;
            b[idx++] = a[l++];
        }   
        else {
            ++count;
            b[idx++] = a[r++];
        }
    }
    while(r <= right) {
        b[idx++] = a[r++];
    }
    while(l <= mid) {
        ans += count;
        b[idx++] = a[l++];
    }
    idx = 0;
    while(left + idx <= right) {
        a[left + idx] = b[idx + 1];
        idx++;
    }
    return ans;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; cin >> a[++i]); // 1 ~ n
    cout << count_inversion(1, n) << '\n';
    // for(int i = 0; i < n; cout << a[++i] << ' ');
}