#include <iostream>
using namespace std;

typedef long long ll;

int n, ans;
ll m, a[1'000'001];

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for(int i = 1; i <= n; cin >> a[i], ++i);

    ll l = 0, mid, r = 1'000'000'000;
    while(l <= r) {
        mid = (l + r) / 2;
        ll tsum = 0;
        for(int i = 1; i <= n; ++i) {
            if(a[i] <= mid) continue;
            tsum += a[i] - mid;
        }
        if(tsum >= m) {
            if(mid > ans) ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << ans;
}