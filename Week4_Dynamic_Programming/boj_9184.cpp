#include <iostream>
using namespace std;

int dp[21][21][21];

int w(const int &a, const int &b, const int &c) {
    if(a <= 0 || b <= 0 || c <= 0)
        return 1;
    if(a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);
    int &ret = dp[a][b][c];
    if(ret) return ret;
    if(a < b && b < c)
        return ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else
        return ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    int a, b, c;
    while(cin >> a >> b >> c) {
        if(a == -1 && b == -1 && c == -1)
            return 0;
        int ret = w(a, b, c);
        cout << "w(" << a <<", " << b << ", " << c << ") = " << ret << '\n';
    }
}