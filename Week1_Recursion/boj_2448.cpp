#include <iostream>
using namespace std;
int n;
char arr[3 * (1 << 10) + 1][3 * (1 << 11) + 1];
void set(int y, int x, int sz) {
    if(sz == 3) {
        arr[y][x] = arr[y + 2][x] = '*';
        arr[y + 1][x - 1] = arr[y + 1][x + 1] = '*';
        for(int i = 1; i <= 2; ++i) {
            arr[y + 2][x + i] = arr[y + 2][x - i] =  '*';
        }
        return;
    }
    int hf = sz / 2;
    set(y, x, hf);
    set(y + hf, x - hf, hf);
    set(y + hf, x + hf, hf);
}
int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= 2 * n + 1; ++j)
        arr[i][j] = ' ';
    }
    set(1, n - 1, n);
    for(int i = 1; i <= n; ++i, cout <<'\n') {
        for(int j = 0; j <= 2 * n; ++j) {
            cout << arr[i][j];
        }
    }
}