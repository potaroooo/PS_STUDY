#include <iostream>
// #define DEBUG
using namespace std;
constexpr int MX = 3'000;

typedef long long ll;

int r, c, h, w, ans = MX * MX + 1, arr[MX + 1][MX + 1], arr2[MX + 1][MX + 1]; 

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> r >> c >> h >> w;
    for(int i = 1; i <= r; ++i) {
        for(int j = 1; j <= c; ++j) {
            cin >> arr[i][j];
        }
    }  

    for(int left = 1, right = r * c, mid = right / 2; left <= right; mid = (left + right) / 2) {
        for(int i = 1; i <= r; ++i) { // 구간합 생성
            for(int j = 1; j <= c; ++j) {
                arr2[i][j] = (arr[i][j] > mid ? 1 : (arr[i][j] == mid ? 0 : -1)) + arr2[i - 1][j] + arr2[i][j - 1] - arr2[i - 1][j - 1];
            }
        }

        #ifdef DEBUG
            cout << "-------------------------------------------\n";
            cout << "mid : " << mid << '\n';
            for(int i = 1; i <= r; ++i) { // 구간합 생성
                for(int j = 1; j <= c; ++j) {
                    cout << arr2[i][j] << ' ';
                }
                cout << '\n';
            }
            cout << "-------------------------------------------\n";
        #endif

        for(int i = h; i <= r; ++i) {
            for(int j = w; j <= c; ++j) {
                if(arr2[i][j] - arr2[i - h][j] - arr2[i][j - w] + arr2[i - h][j - w] <= 0) goto done;
            }
        }
        left = mid + 1;
        continue;
        done :
            ans = mid;
            right = mid - 1;
    }

    cout << ans;
}