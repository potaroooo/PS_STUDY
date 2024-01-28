#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
constexpr int N = 100'001;

typedef long long ll;

ll gcd(ll a, ll b) {
    if(a < b) swap(a, b);
    ll tmp;
    while(true) {
        tmp = a % b;
        if(!tmp) return b;
        a = b, b = tmp;
    }
}

int tc, n;
ll a[N];

ll cool_gcd(const int &left, const int &right) {
    if(left >= right) return a[right];
    if(left + 1 == right) return max(2 * gcd(a[left], a[right]), max(a[left], a[right]));
    int mid = (left + right) / 2;
    ll mx = max(cool_gcd(left, mid - 1), cool_gcd(mid + 1, right));
    int i = mid - 1, j = mid + 1;
    vector<pair<ll, int>> ii, jj;
    ii.push_back({a[mid], mid});
    jj.push_back({a[mid], mid});
    while(i >= left) {
        ll igcd = gcd(ii.back().first, a[i]);
        if(igcd == ii.back().first) ii.back().second = i--;
        else ii.push_back({igcd, i--});
    }
    while(j <= right) {
        ll igcd = gcd(jj.back().first, a[j]);
        if(igcd == jj.back().first) jj.back().second = j++;
        else jj.push_back({igcd, j++});
    }
    for(int i = 0; i < ii.size(); ++i) {
        for(int j = 0; j < jj.size(); ++j) {
            mx = max(mx, gcd(ii[i].first, jj[j].first) * (jj[j].second - ii[i].second + 1));
        }
    }
    return mx;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 0; i < n; cin >> a[++i]);
        cout << cool_gcd(1, n) << '\n';
    }
}