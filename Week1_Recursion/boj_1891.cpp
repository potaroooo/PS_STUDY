#include <iostream>
using namespace std;
typedef long long ll;
int d;
string st;
ll x = 1, dx, y = 1, dy;
void get_xy(ll csz, int lv) {
    if(lv == d) return;
    ll hf = csz >> 1;
    int num = st[lv] - '0';
    if(num > 2) y += hf;
    if(!(num & 2)) x += hf;
    get_xy(csz / 2, lv + 1);
}
void ans(ll yy, ll xx, ll csz) {
    if(csz < 2) return;
    ll hf = csz >> 1;
    ll ny = yy, nx = xx;
    // 1 <= hf, hf < 2 *hf
    if(x < xx + hf) { // 2 or 3
        if(y < yy + hf) cout << '2';
        else {
            cout << '3';
            ny += hf;
        }
    }
    else { // 1 or 4
        nx += hf;
        if(y < yy + hf) cout << '1';
        else {
            cout << '4';
            ny += hf;
        }
    }
    ans(ny, nx, hf);
    return;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> d >> st >> dx >> dy;
    // x y 좌표 구하기
    // x y 좌표에 dx dy를 각각 적용
    // 적용된 좌표에 대해 사분면 구하기
    get_xy(1ll << d, 0);
    x += dx, y -= dy;
    if(x < 1 || y < 1 || x > (1ll << d) || y > (1ll << d)) {
        cout << -1;
        return 0;
    }
    ans(1, 1, 1ll << d);
}