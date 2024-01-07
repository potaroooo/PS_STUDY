#include <iostream>
using namespace std;

int n, a[1'000'001], ans[1'000'001];

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    ans[1] = a[1];
    
    int lis_len = 1;
    for(int i = 2; i <= n; ++i) {
        int last = ans[lis_len];
        if(a[i] > last) {
            ans[++lis_len] = a[i];
            continue;
        }
        for(int left = 1, mid, right = lis_len + 1; left < right;) {
            mid = (left + right) / 2;
            if(ans[mid] >= a[i]) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
            last = right;
        }
        ans[last] = a[i];
        
    }
    cout << lis_len << '\n';
}