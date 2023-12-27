#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
bool vst[100001];
int n, k;
void run() {
    int min = 987654321, cnt = 0;
    queue<pii> q;
    q.push({n, 0});
    while(q.size()) {
        pii cur = q.front();
        q.pop();
        int pos = cur.first, time = cur.second;
        if(pos == k) {
            if(time == min) ++cnt;
            else if(time < min) cnt = 1, min = time;
            continue;
        }
        vst[pos] = true; 
        for(int i = -1; i <= 1; i += 2) {
            int npos = pos + i;
            if(npos < 0 || npos > 100'000 || vst[npos])
                continue;
            q.push({npos, time + 1});
        }
        int tp = 2 * pos;
        if(tp > 100'000 || vst[tp]) continue;
        q.push({tp, time + 1});
    }
    cout << min << '\n' << cnt;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> k;
    run();
}