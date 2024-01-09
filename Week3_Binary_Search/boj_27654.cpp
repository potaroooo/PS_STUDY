#include <iostream>
#include <algorithm>
#include <cmath>
#define DEBUG
using namespace std;

typedef pair<int, int> pii;

int n, k;
double ans, c;
pii x[100'001];

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cout << fixed;
    cout.precision(7);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i].first >> x[i].second;
    }
    for(double left = 0, right = 1, mid = 0.5; left + 0.0000000001 < right; mid = (left + right) / 2) {
        c = mid;
        sort(x + 1, x + 1 + n, [&](const pii &a, const pii &b) {
            double aa = a.first - c * a.second, bb = b.first - c * b.second;
            return aa > bb;
        });
        double tmp = 0.0;
        for(int i = 1; i <= k; ++i) {
            tmp += (x[i].first - c * x[i].second);
        }
        ans = mid;
        if(tmp >= 0) {
            left = mid;
        }
        else {
            right = mid;
        }        
    }
    cout << ans << '\n';  
}