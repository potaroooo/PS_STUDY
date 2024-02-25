#include <iostream>
#include <cmath>
using namespace std;

int s, n, k, r1, r2, c1, c2;
int a[51][51];

void dnc(int len, int y, int x) {
    if(len < n) return;
    int mxy = y + len - 1,
    mxx = x + len - 1;
    if(mxy < r1 || y > r2 || mxx < c1 || x > c2) return;
    // 정답 배열 처리
    int nlen = len / n;
    int gap = len - k * nlen >> 1;
    int ys = max(r1, y + gap),
    ye = min(r2, mxy - gap),
    xs = max(c1, x + gap),
    xe = min(c2, mxx - gap);
    for(int yy = ys; yy <= ye; ++yy) {
        for(int xx = xs; xx <= xe; ++xx) {
            a[yy - r1][xx - c1] = 1;
        }
    }
    // 가지치기를 수행하며 다음 평면 생성
    for(int ny = 0; ny < len; ny += nlen) {
        for(int nx = 0; nx < len; nx += nlen) {
            if(ys <= ny && ny <= ye && xs <= nx && nx <= xe)
                continue;
            dnc(nlen, y + ny, x + nx);
        }
    }
}
int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;
    if(!s) {
        string zr = string(c2 - c1 + 1, '0') + "\n";
        for(int y = r1; y <= r2; ++y)
            cout << zr;
        return 0;
    }
    int len = 1;
    while(s--) len *= n;
    dnc(len, 0, 0);
    for(int y = r1; y <= r2; ++y, cout << '\n') {
        for(int x = c1; x <= c2; ++x)
            cout << a[y - r1][x - c1];
    }
}
