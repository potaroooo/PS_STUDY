#include <iostream>
using namespace std;
constexpr int MX_LEN = 1 << 7;

int K, len, a[MX_LEN + 2][MX_LEN + 2], tile_cnt = 1;

bool find_hole(int y, int x, int len) {
    for(int i = 0;  i < len; ++i) {
        for(int j = 0; j < len; ++j) {
            if(a[y + i][x + j] != 0) return true;
        }
    }
    return false;
}

void flooring(int y, int x, int len) {
    if(len == 2) {
        for(int i = 0; i < len; ++i) {
            for(int j = 0; j < len; ++j) {
                if(!a[y + i][x + j]) a[y + i][x + j] = tile_cnt;
            }
        }
        ++tile_cnt;
        return;
    }
    int nxt_len = len >> 1;
    if(!find_hole(y, x, nxt_len)) {
        a[y + nxt_len - 1][x + nxt_len - 1] = tile_cnt;
    }
    if(!find_hole(y, x + nxt_len, nxt_len)) {
        a[y + nxt_len - 1][x + nxt_len] = tile_cnt;
    }
    if(!find_hole(y + nxt_len, x, nxt_len)) {
        a[y + nxt_len][x + nxt_len - 1] = tile_cnt;
    }
    if(!find_hole(y + nxt_len, x + nxt_len, nxt_len)) {
        a[y + nxt_len][x + nxt_len] = tile_cnt;
    }
    ++tile_cnt;
    flooring(y, x, nxt_len);
    flooring(y, x + nxt_len, nxt_len);
    flooring(y + nxt_len, x, nxt_len);
    flooring(y + nxt_len, x + nxt_len, nxt_len);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    int x, y;
    cin >> K >> x >> y;
    len = 1 << K;
    a[y][x] = -1;
    flooring(1, 1, len);
    for(int i = len; i; --i, cout << '\n') {
        for(int j = 1; j <= len; ++j) {
            cout << a[i][j] << ' ';
        }
    }
}