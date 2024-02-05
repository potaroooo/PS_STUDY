#include <iostream>
using namespace std;
constexpr long long M = 85;
typedef long long ll;

int tc;
ll n, k, L[M + 1]{0, 2, 2};

char rec(ll lv, ll pos) {
    if(pos <= 0 || pos > L[lv]) return '0'; // pos가 Llv 내에 존재하지 않는 경우
    if(n <= 2) return "()"[pos - 1]; // 기저 케이스
    if(pos == 1) return '('; // 1이면 왼쪽 끝을 나타내므로 (
    else if(pos == L[lv]) return ')'; // pos가 Llv와 같다면 오른쪽 끝을 나타내므로 )
    else if(pos <= L[lv - 2] + 1) return rec(lv - 2, pos - 1); // pos가 lv - 2에 해당하는 S에 속함
    else return rec(lv - 1, pos - L[lv - 2] - 1); // pos가 lv - 1에 해당하는 S에 속함
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    for(int i = 3; i <= M + 1; ++i) // Ls 전처리
        L[i] = L[i - 2] + L[i - 1] + 2LL;
    cin >> tc;
    while(tc--) {
        cin >> n >> k;
        if(n > M + 1) {
            k = k - (n - M) / 2;
            n = n - (n - M) / 2 * 2;
            if(k < 0) {
                cout << "(\n";
                continue;
            }
        }
        cout << rec(n, k) << '\n';
    }
}