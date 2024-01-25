#include <iostream>
#include <stdlib.h>
using namespace std;
constexpr int N = 500'000;

int n, k, a[N + 1], b[N + 1], cnt;

void merge_sort(int left, int right) {
    if(left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    merge_sort(left, mid);
    merge_sort(mid + 1, right);
    int idx = 1, l = left, r = mid + 1;
    while(l <= mid && r <= right) {
        b[idx] = a[l] <= a[r] ?
            a[l++] : a[r++];
        ++idx;
    }
    while(l <= mid) {
        b[idx++] = a[l++];
    }
    while(r <= right) {
        b[idx++] = a[r++];
    }
    l = left, idx = 1;
    while(l <= right) {
        ++cnt;
        if(cnt == k) {
            cout << b[idx];
            exit(0);
        }
        a[l++] = b[idx++];
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    merge_sort(1, n);
    if(cnt < k) cout << "-1";
}