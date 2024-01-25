#include <iostream>
using namespace std;

typedef long long ll;

ll po(ll n, ll t, ll mod) {
    if(t == 1LL) return n % mod;
    ll ret = po(n, t >> 1LL, mod);
    ret = ret * ret % mod;
    if(t & 1LL) ret = ret * n % mod;
    return ret % mod;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    
    ll a, b, c;
    cin >> a >> b >> c;
    cout << po(a, b, c);
}