#include <iostream>
using namespace std;
int n;
char arr[2188][2188];
void st(int y, int x, int len) {
    if(len == 1) { // 기저
        arr[y][x] = '*';
        return;
    }
    int nlen = len / 3;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(i * j == 1)
                continue;
            int ny = y + i * nlen,
                nx = x + j * nlen;
            st(ny, nx, nlen);
        }
    }
}
int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j)
            arr[i][j] = ' ';
    }
    st(1, 1, n);
    for(int i = 1; i <= n; ++i, cout << '\n') {
        for(int j = 1; j <= n; ++j) {
            cout << arr[i][j];
        }
    }
}