#include <iostream>
using namespace std;
int n, r, c;
void z(int y, int x, int sz, int cnt) {
    if(sz == 2) {
        for(int i = y; i < y + 2; ++i)
            for(int j = x; j < x + 2; ++j){
                if(i == r && j == c){
                    cout << cnt;
                    break;
                }
                ++cnt;
            }
        exit(0);
    }
    int hf = sz / 2;
    int dif = hf * hf;
    if(r < y + hf && c < x + hf) {
        z(y, x, hf, cnt);
        return;
    }
    if(r < y + hf && c < x + 2 * hf) {
        z(y, x + hf, hf, cnt + dif);
        return;
    }
    if(r < y + 2 * hf && c < x + hf) {
        z(y + hf, x, hf, cnt + 2 * dif);
        return;
    }
    if(r < y + 2 * hf && c < x + 2 * hf) {
        z(y + hf, x + hf, hf, cnt + 3 * dif);
        return;
    }
}
int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> r >> c;
    z(0, 0, 1 << n, 0);
}