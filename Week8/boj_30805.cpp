#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
// #define DEBUG
using namespace std;
constexpr int MX = 100;
typedef pair<int, int> pii;

int N, M;
pii A[MX + 1], B[MX + 1];

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    auto cmp = [](const pii &a, const pii& b) {
        if(a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    };
    cin >> N;
    for(int i = 1; i <= N; ++i) {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A + 1, A + 1 + N, cmp);
    #ifdef DEBUG
    cout << "sorted A : \n";
    for(int i = 1; i <= N; ++i) {
        cout << A[i].first << ' ' << A[i].second << '\n';
    }
    #endif
    cin >> M;
    for(int i = 1; i <= M; ++i) {
        cin >> B[i].first;
        B[i].second = i;
    }
    sort(B + 1, B + 1 + M, cmp);
    #ifdef DEBUG
    cout << "sorted B : \n";
    for(int i = 1; i <= M; ++i) {
        cout << B[i].first << ' ' << B[i].second << '\n';
    }
    #endif
    vector<int> ans;
    int aidx = 0, bidx = 0, bidx2 = 0;
    for(int i = 1; i <= N; ++i) {
        int num_a = A[i].first, ia = A[i].second;
        #ifdef DEBUG
        cout << "num_a : " << num_a << '\n';
        #endif
        if(ia < aidx) continue;
        for(int j = bidx2 + 1; j <= M; ++j) {
            int num_b = B[j].first, ib = B[j].second;
            #ifdef DEBUG
            cout << "j : " << j << '\n';
            cout << "bidx : " << bidx << '\n';
            cout << "num_b, ib : " << num_b <<  ", " << ib << '\n';
            #endif
            if(ib < bidx || num_b != num_a) continue;
            ans.push_back(num_b);
            aidx = ia, bidx = ib, bidx2 = j;
            break;
        }
    }
    cout << ans.size();
    if(ans.size()) {
        cout << '\n';
        for(const int& num : ans) cout << num << ' ';
    }
}