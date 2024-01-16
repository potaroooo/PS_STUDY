#include <iostream>
#include <limits.h>
// #define DEBUG
using namespace std;
constexpr long long MX = INT64_MAX;
constexpr int K = 5000 + 1;

int tc, k, a[K];
long long dp[K][K], dp2[K][K], sum[K];

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
            dp2[i][i] = i;
        }

        for(int len = 2; len <= k; ++len) { // 구간의 길이
            for(int left = 1; left <= k - len + 1; ++left) { // 구간 시작점
                int right = left + len - 1; // 구간 끝점
                dp[left][right] = MX;
                for(int mid = dp2[left][right - 1]; mid <= dp2[left + 1][right]; ++mid) { // 구간 분할점(커누스 최적화)
                    long long cost = dp[left][mid] + dp[mid + 1][right] + sum[right] - sum[left - 1];
                    #ifdef DEBUG
                    cout << "left : " << left << ", mid : " << mid << ", right : " << right << ", cost : " << cost << '\n';
                    #endif
                    if(cost < dp[left][right]) {
                        dp[left][right] = cost;
                        dp2[left][right] = mid; // 구간을 최적으로 분할하는 분할점 저장
                    }
                }
            }
        }

        cout << dp[1][k] << '\n';
    }

}