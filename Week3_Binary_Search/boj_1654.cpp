#include <iostream>
using namespace std;

typedef long long ll;

int n, k;
ll arr[10'001], ans, mx = 0;

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    
    cin >> k >> n;
    for(int i = 1; i <= k; ++i) {
        ll &a = arr[i];
        cin >> a;
        if(a > mx) mx = a;
    }
    
    ll mn = 1, md; 
    while(mn <= mx) {
        md = (mn + mx) / 2;
        ll sum = 0;
        for(int i = 1; i <= k; ++i) {
            sum += arr[i] / md;
        }
        if(sum >= n) {
            if(md >= ans) ans = md;
            mn = md + 1;
        }
        else {
            mx = md - 1;
        }
    }
    cout << ans;
}