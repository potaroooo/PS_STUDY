#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
const pii d[] {
    {-1, 0},
    {-1, 1},
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1},
    {0, -1},
    {-1, -1}
};
int w, h;
char a[51][51];
void run(int y, int x) {
    a[y][x] = '0';
    queue<pii> q;
    q.push({y, x});
    while(q.size()) {
        pii cur = q.front();
        q.pop();
        int cy = cur.first, cx = cur.second;
        for(int i = 0; i < 8; ++i) {
            int ny = cy + d[i].first, nx = cx + d[i].second;
            if(ny <= 0 || nx <= 0 || ny > h || nx > w ||
               a[ny][nx] == '0') continue;
            a[ny][nx] = '0';
            q.push({ny, nx});
        }
    }
}
int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    while(true) {
        cin >> w >> h;
        if(w * h <= 0) break;
        int ans = 0;
        for(int y = 1; y <= h; ++y) {
            for(int x = 1; x <= w; ++x) {
                cin >> a[y][x];
            }
        }
        for(int y = 1; y <= h; ++y) {
            for(int x = 1; x <= w; ++x) {
                if(a[y][x] == '1') {
                    ++ans;
                    run(y, x);
                }
            }
        }
        cout << ans << '\n';
    }
}