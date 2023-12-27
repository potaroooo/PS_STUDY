#include <iostream>
#include <queue>
#define y first
#define x second
using namespace std;
typedef pair<int, int> pii;
const int d[] = {-1, 0, 1, 0};
int n, m, box[1001][1001];
queue<pii> q;
int run() {
    while(q.size()) {
        pii cur = q.front();
        q.pop();
        int cy = cur.y, cx = cur.x;
        for(int i = 0; i < 4; ++i) {
            int ny = cy + d[i], nx = cx + d[3 - i];
            if(ny <= 0 || nx <= 0 || ny > n || nx > m || box[ny][nx])
                continue;
            box[ny][nx] = box[cy][cx] + 1;
            q.push({ny, nx});
        }
    }
    int ret = 0;
    for(int yy = 1; yy <= n; ++yy) {
        for(int xx = 1; xx <= m; ++xx) {
            if(box[yy][xx] < 0) continue;
            if(box[yy][xx] == 0) {
                return -1;
            }
            if(box[yy][xx] > ret) ret = box[yy][xx];
        }
    }
    return ret - 1;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> m >> n;
    for(int yy = 1; yy <= n; ++yy) {
        for(int xx = 1; xx <= m; ++xx) {
            cin >> box[yy][xx];
            if(box[yy][xx] > 0) q.push({yy, xx});
        }
    }
    cout << run();
}