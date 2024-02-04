#include <iostream>
#include <vector>
#include <algorithm>
// #define DEBUG
using namespace std;
constexpr int MX = 100'001;

int N, M, A[MX];
vector<int> sgt[(MX << 2) + 5];

vector<int> init(int node, int left, int right) {
    if(left == right) {
        sgt[node].push_back(A[left]);
        return sgt[node];
    }
    int mid = (left + right) / 2;
    vector<int> l = init(node * 2, left, mid),
    r = init(node * 2 + 1, mid + 1, right);
    auto ll = l.begin(), rr = r.begin();
    while(ll != l.end() || rr != r.end()) {
        if(ll == l.end()) {
            sgt[node].push_back(*rr);
            ++rr;
        }
        else if(rr == r.end()) {
            sgt[node].push_back(*ll);
            ++ll;
        }
        else {
            if(*ll < *rr) {
                sgt[node].push_back(*ll);
                ++ll;
            }
            else { 
                sgt[node].push_back(*rr);
                ++rr;
            }
        }
    }
    #ifdef DEBUG
    cout << "before initialized : node, left, right : " << node << ' ' << left << ' ' << right << '\n';
    for(int i = left; i <= right; ++i) {
        cout << A[i] << ' ';
    }
    cout << '\n';
    cout << "initialized : node, left, right : " << node << ' ' << left << ' ' << right << '\n';
    for(const int &i : sgt[node]) {
        cout << i << ' ';
    }
    cout << '\n';
    #endif
    return sgt[node];
}

int query(int node, int left, int right, int st, int ed, int val) {
    if(ed < left || st > right) return 0;
    #ifdef DEBUG
    cout << "cur rec : node, left, right : " << node << ' ' << left << ' ' << right << '\n';
    for(const int &i : sgt[node]) {
        cout << i << ' ';
    }
    cout << '\n';
    #endif
    if(st <= left && right <= ed)
        return sgt[node].end() - upper_bound(sgt[node].begin(), sgt[node].end(), val);
    int mid = (left + right) / 2;
    return
    query(node * 2, left, mid, st, ed, val) +
    query(node * 2 + 1, mid + 1, right, st, ed, val);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> N;
    for(int i = 0; i < N; cin >> A[i++]);
    init(1, 0, N - 1);
    cin >> M;
    while(M--) {
        int i, j, k;
        cin >> i >> j >> k;
        cout << query(1, 0, N - 1, i - 1, j - 1, k) << '\n';
    }
}
