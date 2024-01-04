#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, a[50'001];

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    int mx = 0, mn = 987654321;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        if(a[i] > mx) mx = a[i];
        if(a[i] < mn) mn = a[i];
    }
    sort(a + 1, a + 1 + n);

    int l = 1, m, r = mx, ans = 0;
    while(l <= r) {
        m = (l + r) / 2;
        bool flag = false;
        ll sum = 0;
        for(int i = 1; i <= n; ++i) {
            sum += m;
            if(sum > a[i]) {
                flag = true;
                break;
            }
        }
        if(flag) {
            r = m - 1;
        }
        else {
            if(m > ans) ans = m;
            l = m + 1;
        }
    }
    cout << ans;
}