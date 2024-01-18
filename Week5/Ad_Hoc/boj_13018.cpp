#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    if(n == k) {
        cout << "Impossible\n";
        return 0;
    }

    int swap_cnt = n - k - 1;
    int *a = new int[n + 2];
    for(int i = 1; i <= n; ++i) {
        a[i] = i;
    }
    for(int i = 1; i <= swap_cnt; ++i) {
        swap(a[i], a[i + 1]);
    }
    for(int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
}