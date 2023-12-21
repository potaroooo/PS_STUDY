#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
map<ll, ll> m;
ll n, p, q;
ll func(ll cur) {
    ll &ret = m[cur];
    if(ret != 0) return ret;
    return ret = func(cur / p) + func(cur / q);
}
int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    m[0] = 1;
    cin >> n >> p >> q;
    cout << func(n);
}