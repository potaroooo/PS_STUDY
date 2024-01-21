#include <iostream>
#include <cmath>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll MX = 1'000'000'001;
const ll MN = -1'000'000'001;
const int N = 500'000;

int n;
pll thief, officer[N + 1];

ll get_dist(const pll &a, const pll &b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    pll escape[] = {
        {0, MX}, // y가 최소인 지점
        {0, MN}, // y가 최대인 지점
        {MX, 0}, // x가 최소인 지점
        {MN, 0}  // x가 최대인 지점
    };
    for(int i = 1; i <= n; ++i) {
        pll &cur = officer[i];
        cin >> cur.x >> cur.y;
        if(cur.x > escape[3].x) escape[3].x = cur.x;
        if(cur.x < escape[2].x) escape[2].x = cur.x;
        if(cur.y > escape[1].y) escape[1].y = cur.y;
        if(cur.y < escape[0].y) escape[0].y = cur.y;
    }
    cin >> thief.x >> thief.y;
    escape[0].x = escape[1].x = thief.x;
    escape[2].y = escape[3].y = thief.y;

    int chk = 0; // 탐색 후 chk == 15면 탈출 불가능
    for(int i = 0; i <= 3; ++i) {
        for(int j = 1; j <= n; ++j) {
            ll dist_officer = get_dist(officer[j], escape[i]),
            dist_thief = get_dist(thief, escape[i]);
            if(dist_officer <= dist_thief) {
                chk |= (1 << i);
                break;
            }
        }
    }
    if(chk == 15) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }
}