#include <iostream>
// #define DEBUG
using namespace std;
constexpr int MX = 1'000;

string a = " ", b = " ";
int dp[MX + 1][MX + 1];

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    string ipt;
    cin >> ipt;
    a += ipt;
    cin >> ipt;
    b += ipt;
    for(int i = 1, a_len = a.length(); i < a_len; ++i) {
        for(int j = 1, b_len = b.length(); j < b_len; ++j) {
            if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
        }
    }

    #ifdef DEBUG
    for(int i = 1; i < a.length(); ++i) {
        for(int j = 1; j < b.length(); ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    #endif
    cout << dp[(int)a.length() - 1][(int)b.length() - 1];
}