#include <iostream>
#include <queue>
using namespace std;
typedef struct status {
    int y, x, cnt = 1, brk = 1;
} stt;
const int d[]{-1, 0, 1, 0};
int n, m;
string arr[1000];
bool chk[2][1000][1000];
int run() {
    chk[0][0][0] = chk[1][0][0] = true; 
    queue<stt> q;
    q.push({0, 0});
    while(q.size()) {
        stt cur = q.front();
        q.pop();
        if(cur.y == n && cur.x == m) {
            return cur.cnt;
        }
        for(int i = 0; i < 4; ++i) {
            int ny = cur.y + d[i],
            nx = cur.x + d[3 - i];
            if(ny < 0 || nx < 0 || ny > n || nx > m)
                continue;
            if(arr[ny][nx] == '1') {
                if(!cur.brk) continue;
                chk[0][ny][nx] = true;
                q.push({ny, nx, cur.cnt + 1, 0});
            }
            else {
                if(chk[cur.brk][ny][nx]) continue;
                chk[cur.brk][ny][nx] = true;
                q.push({ny, nx, cur.cnt + 1, cur.brk});
            }
        }
    }
    return -1;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i]; 
    }
    --n, --m;
    cout << run();
}