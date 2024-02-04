#include <iostream>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;

set<long long> chk{0, 1, 2};
ll n;

void ans(ll num) {
    chk.insert(num);
    ll x = sqrt(num), y;
    if(x * x != num) ++x;
    y = x * x - num;
    if(chk.find(x) == chk.end()) ans(x);
    if(chk.find(y) == chk.end()) ans(y);
    cout << x << ' ' << y << '\n';
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    if(n <= 2) return 0;
    ans(n);
}