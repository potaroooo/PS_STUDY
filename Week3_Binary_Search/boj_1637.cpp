#include <iostream>
#include <climits>
// #define DEBUG
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
constexpr ll MX = INT32_MAX;

typedef struct abc {
    ll a, c, b;
} abc;

int n;
ll ans;
abc arr[20'001];

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for(int i = 1; i <= n; cin >> arr[i].a >> arr[i].c >> arr[i].b, ++i);

    auto get_counts = [] (ll val) {
            ll cnt = 0;
            for(int i = 1; i <= n; ++i) {
            abc &cur = arr[i];
            if(val < cur.a) continue;
            ll min_c = cur.c < val ? cur.c : val;
            cnt += (1 + (min_c - cur.a) / cur.b);
            }
            return cnt;
    };

    for(ll left = 1, right = MX, mid = (left + right) / 2; left <= right; mid = (left + right) / 2) { 
        ll cnt = 0;
        cnt = get_counts(mid);
        #ifdef DEBUG
            cout << mid << ' ' << cnt << '\n';
        #endif
        if(cnt & 1) { // 개수가 홀수인 수가 포함된 구간
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1; 
        }
    }
    if(ans) cout << ans << ' ' << get_counts(ans) - get_counts(ans - 1);
    else cout << "NOTHING"; 
}