#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define x first
#define y second
using namespace std;
constexpr int N = 100'001;
constexpr long long INF = 987654321000LL;

typedef long long ll;
typedef pair<int, int> pii;

int n;
pii a[N];

ll mn(const ll &a, const ll &b) {
    return a < b ? a : b;
}

ll sqr (const ll &a) {
    return a * a;
}

ll dist(const pii &a, const pii &b) {
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

ll closest_pair(int left, int right) {
    if(left == right) return INF;
    if(right - left == 1) {
        return dist(a[left], a[right]);
    }
    int mid = (left + right) / 2;
    ll min_dist = mn(closest_pair(left, mid), closest_pair(mid + 1, right));
    vector<pii> cur_group;
    int idx = mid;
    while(idx >= left && abs(a[mid].x - a[idx].x) < min_dist) {
        cur_group.push_back(a[idx--]);
    }
    idx = mid + 1;
    while(idx <= right && abs(a[mid].x - a[idx].x) < min_dist) {
        cur_group.push_back(a[idx++]);
    }
    sort(cur_group.begin(), cur_group.end(), [](const pii &a, const pii &b) {
        return a.y < b.y;
    });
    for(int i = 0, sz = cur_group.size(); i < sz - 1; ++i) {
        for(int j = i + 1; j < sz; ++j) {
            const auto &pi = cur_group[i], &pj = cur_group[j];
            if(sqr(pi.y - pj.y) >= min_dist) break;
            if(sqr(pi.x - pj.x) >= min_dist) continue;
            min_dist = mn(min_dist, dist(pi, pj));
        }
    } 
    return min_dist;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; cin >> a[++i].x >> a[i].y);
    sort(a + 1, a + 1 + n, [](const pii& a, const pii& b) {
        return a.x < b.x;
    });
    cout << closest_pair(1, n);
}