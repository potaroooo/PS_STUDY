#include <iostream>
#include <algorithm>
using namespace std;

int n, m, arr[100'001];

string bsrch(int l, int r, int num) {
    int m;
    while(l <= r) {
        m = (l + r) / 2;
        if(num == arr[m]) {
            return "1\n";
        }
        if(num < arr[m]) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return "0\n";
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; cin >> arr[i], ++i);
    sort(arr + 1, arr + 1 + n);

    cin >> m;
    for(int i = 1; i <= m; ++i) {
        int j;
        cin >> j;
        cout << bsrch(1, n, j);
    }
}