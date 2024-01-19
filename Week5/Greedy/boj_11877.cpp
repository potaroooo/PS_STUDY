#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    ll n, x;
    cin >> n >> x;
    if(x > (n - 1) * (n - 2) / 2) {
        cout << -1;
        return 0;
    }

    bool *c = new bool[n - 1]{0, };
    cout << n << ' ';
    ll low_bar = 1;
    while(true) {
        if(x > n - 1 - low_bar) {
            cout << low_bar << ' ';
            x -= n - 1 - low_bar;
            c[low_bar] = true;
            ++low_bar;
        }
        else {
            ll cur_bar = n - 1 - x;
            cout << cur_bar << ' ';
            x -= cur_bar; // 여기서 x == 0LL이 되어야 함.
            c[cur_bar] = true;
            break;
        }
    }
    cout << n - 1 << ' ';
    for(int i = n - 2; i >= 1; --i)
        if(!c[i]) cout << i << ' ';
}