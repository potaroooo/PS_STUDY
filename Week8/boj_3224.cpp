#include <iostream>
#include <vector>
#include <cmath>
// #define DEBUG
using namespace std;
typedef pair<int, int> pii;

vector<pii> v, ans;
int N;

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> N;
    for(int i = 0, ipt; i < N; ++i) {
        cin >> ipt;
        if(v.empty()) {
            v.push_back({ipt, ipt});
            continue;
        }
        int cur_min = ipt, cur_max = ipt;
        while(v.size()) {
            if(cur_min == v.back().first - 1) {
                cur_max = v.back().second;
                v.pop_back();
                ans.push_back({cur_min, cur_max});
                continue;
            }
            if(cur_min == v.back().second + 1) {
                cur_min = v.back().first; 
                v.pop_back();
                ans.push_back({cur_min, cur_max});
                continue;
            }
            if(cur_max == v.back().first - 1) {
                cur_max = v.back().second;
                v.pop_back();
                ans.push_back({cur_min, cur_max});
                continue;
            }
            if(cur_max == v.back().second + 1) {
                cur_min = v.back().first;
                v.pop_back();
                ans.push_back({cur_min, cur_max});
                continue;
            }
            break;
        }
        v.push_back({cur_min, cur_max});
    }
    #ifdef DEBUG
    cout << "ans_size : " << ans.size() << '\n';
    for(const auto& pii : ans) {
            cout << pii.first << ' ' << pii.second << '\n';
    }
    #endif
    if(ans.size() != N - 1) cout << "NE";
    else {
        cout << "DA\n";
        for(const auto& pii : ans) {
            cout << pii.first << ' ' << pii.second << '\n';
        }
    }
}