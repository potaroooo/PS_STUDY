#include <iostream>
using namespace std;
constexpr int MX = 100'000;

int N, a[MX + 5];

void dnc(int l, int r) {
    if(l > r) return;
    if(l == r) {
        a[l] = 1;
        return;
    }
    int m = l + r >> 1;
    dnc(l, m);
    dnc(m + 1, r);
    for(int i = l; i <= m; ++i) {
        a[i] <<= 1;
        --a[i];
    }
    for(int j = m + 1; j <= r; ++j) {
        a[j] <<= 1;
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> N;
    dnc(1, N);
    for(int i = 1; i <= N; ++i)
        cout << a[i] << ' ';
}
