#include <iostream>
#include <cmath>
using namespace std;
constexpr int MX = 100'000;

int N, A[MX + 1];
long long dp[MX + 1];

long long get_bit_count(int num) {
    int ret = 0;
    for(int i = 0; i <= 10; ++i) {
        if(num & (1 << i)) ++ret;
    }
    return ret;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> N;
    for(int i = 1; i <= N; cin >> A[i++]);
    dp[2] = get_bit_count(A[1] ^ A[2]);
    dp[3] = get_bit_count(A[1] ^ A[2] ^ A[3]);
    dp[4] = dp[2] + get_bit_count(A[3] ^ A[4]);
    for(int i = 5; i <= N; ++i) {
        long long prev2 = dp[i - 2] + get_bit_count(A[i - 1] ^ A[i]),
        prev3 = dp[i - 3] + get_bit_count(A[i - 2] ^ A[i - 1] ^ A[i]);
        dp[i] = max(prev2, prev3);
    }
    cout << dp[N];
}