#include <iostream>
using namespace std;

typedef long long ll;

ll mn(ll a, ll b) {
    return a < b ? a : b;
}

ll n, k, ans;

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> k;
    for(ll left = 1, right = k, mid = (left + right) / 2; left <= right; mid = (left + right) / 2) {
        ll cnt = 0;
        for(ll i = 1; i <= n; ++i) {
            cnt += mn(mid / i, n);
        }
        if(cnt >= k) {
            ans = mid;
            right = mid - 1;
        } 
        else {
            left = mid + 1;
        }
    }
    cout << ans;
}