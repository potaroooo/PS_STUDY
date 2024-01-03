#include <iostream>
using namespace std;

typedef long long ll;

int n, a[1000][1000], mx = 0;
ll sum;

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    
    cin >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> a[i][j];
            sum += (ll) a[i][j];
            if(a[i][j] > mx) mx = a[i][j];
        }
    }
    if(sum == 0) {
        cout << 0;
        return 0;
    }
    int mn = 0, md, ans = 10'000'001; 
    while(mn <= mx) {
        md = (mn + mx) / 2;
        ll tsum = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                tsum += (a[i][j] < md ? a[i][j] : md);
            }
        }
        tsum = (tsum * 100) / sum;
        if(tsum >= 50) {
            if(md < ans) ans = md;
            mx = md - 1;
        }
        else {
            mn = md + 1;
        }
    }
    cout << ans;
} 