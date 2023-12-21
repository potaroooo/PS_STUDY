#include <iostream>
#define N 12
using namespace std;
int n, x, y, ans, arr[N * 2 + 1];
void rpd(int pos, int chk) {
    if(chk == (1 << (n + 1)) - 1) { // 모든 숫자를 조건에 맞게 배치했음
        ++ans;
        return;
    }
    if(arr[pos] != 0) { // 이미 배치된 위치라면 넘어간다
        rpd(pos + 1, chk);
        return;
    }
    for(int i = 1; i <= n; ++i) {
        if(chk & (1 << i)) continue; // 이미 사용된 숫자면 이하의 과정이 무의미함
        int req = i + 1;
        if(req + pos > (n << 1) || arr[req + pos] != 0) continue; // 현재 위치에서 해당 숫자를 모두 배치할 수 없음
        arr[pos] = arr[pos + req] = i;
        rpd(pos + 1, chk | (1 << i));
        arr[pos] = arr[pos + req] = 0;
    }
}
int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> x >> y;
    int fxd = y - x - 1;
    arr[y] = arr[x] = fxd;
    rpd(1, 1 | (1 << fxd));
    cout << ans << '\n';
}