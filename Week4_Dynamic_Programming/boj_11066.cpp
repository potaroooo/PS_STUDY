#include <iostream>
using namespace std;
// #define DEBUG
constexpr int MX = 987654321;

int tc, k, a[501], sum[501], dp[501][501];

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> tc;
    for(int t = 1; t <= tc; ++t) {
        cin >> k;
        for(int i = 1; i <= k; ++i) {
            cin >> a[i];
            sum[i] = a[i] + sum[i - 1];
        }

        for(int len = 2; len <= k; ++len) { // 구간의 길이
            for(int left = 1; left <= k - len + 1; ++left) { // 구간 시작점
                int right = left + len - 1; // 구간 끝점
                dp[left][right] = MX;
                for(int mid = left; mid < right; ++mid) { // 구간 분할점
                    int cost = dp[left][mid] + dp[mid + 1][right] + sum[right] - sum[left - 1];
                    #ifdef DEBUG
                    cout << "left : " << left << ", mid : " << mid << ", right : " << right << ", cost : " << cost << '\n';
                    #endif
                    if(cost < dp[left][right]) dp[left][right] = cost;
                }
            }
        }

        cout << dp[1][k] << '\n';
    }

}