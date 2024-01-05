#include <iostream>
#include <algorithm>
using namespace std;

int n, c, x[200'001];

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> c;
    for(int i = 1; i <= n; cin >> x[i], ++i);
    sort(x + 1, x + 1 + n);

    int left = 1, mid, right = x[n] - x[1], ans = 0;
    while(left <= right) {
        mid = (left + right) / 2;
        int cnt = 1;
        for(int i = 2, prev = x[1]; i <= n; ++i) {
            if(x[i] - prev >= mid) {
                prev = x[i];
                ++cnt;
            }
        }
        if(cnt >= c) { // 거리를 늘려야 함.
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << ans;
}