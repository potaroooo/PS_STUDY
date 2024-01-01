#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#define y first
#define x second
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

const pii d[]{ // 8방향
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1},           {0, 1},
    {1, -1}, {1, 0},   {1, 1}
};

int n;
pii arr[100'001]; // 잔디 배열
map<pii, int> m; // 잔디 기록
bool chk[100'001]{true}; // 방문 배열

ll dist(const pii &a) { // 해당 페어의 맨해튼 거리 반환
    return abs(a.y) + abs(a.x);
}

void find_connected_grass(const int &cur_idx) { // dfs 방식으로 현재 잔디와 연결된 잔디를 찾아서 방문 처리함
    const pii cur = arr[cur_idx];
    for(int i = 0; i < 8; ++i) {
        const pii nxt = {cur.y + d[i].y, cur.x + d[i].x};
        int nxt_idx = m[nxt];
        if(chk[nxt_idx]) continue;
        chk[nxt_idx] = true;
        find_connected_grass(nxt_idx);
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0); // fastio
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i].x >> arr[i].y;
    }
    sort(arr + 1, arr + 1 + n, [](const pii &a, const pii &b) 
        {
            ll dist_a = dist(a),
            dist_b = dist(b);
            return dist_a < dist_b;
        }
    ); // 페어간의 맨해튼 거리를 비교해서 오름차순으로 정렬
    for(int i = 1; i <= n; ++i) { // 정렬된 페어들을 맵에 기록
        m[arr[i]] = i;
    }

    ll ans = 0LL; 
    int last_idx = 0;
    for(int i = 1; i <= n; ++i) {
        if(chk[i]) continue; // 이미 방문한 잔디면 넘어감
        chk[i] = true; // 방문 처리
        last_idx = i; // 마지막으로 순회한 잔디 기록
        ans += 2 * dist(arr[i]); // 순회한 잔디의 맨해튼 거리 * 2만큼 ans에 추가
        find_connected_grass(i); // 연결된 잔디 탐색
    }
    ans -= dist(arr[last_idx]); // 마지막으로 순회한 잔디의 맨해튼 거리가 가장 길 것이므로 해당 맨해튼 거리만큼 뺌
    cout << ans << '\n';
}