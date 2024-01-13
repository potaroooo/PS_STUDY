#include <iostream>
#include <limits.h>
// #define DEBUG
using namespace std;

typedef pair<int, int> pii;

constexpr int MX = INT32_MAX;
int n, dp[501][501];
pii arr[501];
 
int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }

    for(int len = 1; len <= n; ++len) { // 구간 길이
        for(int left = 1; left <= n - len + 1; ++left) { // 구간 시작점
            int right = left + len - 1; // 구간 끝점
            if(left == right) {
                dp[left][right] = 0;
                continue;
            }
            dp[left][right] = MX;
            for(int mid = left; mid < right; ++mid) { // 구간 분할점
                int cost = dp[left][mid] + dp[mid + 1][right] + arr[left].first * arr[mid].second * arr[right].second;
                if(cost < dp[left][right]) dp[left][right] = cost;
                #ifdef DEBUG 
                cout << "left : " << left << ", mid : " << mid << ", right : " << right << ", cost : " << cost << '\n';
                #endif                 
            }
        }
    }
    
    cout << dp[1][n] << '\n';
}