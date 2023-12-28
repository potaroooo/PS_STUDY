#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int n, m, cnt[1001];
vector<int> v[1001];
void run() {
    vector<int> streak;
    queue<int> q;
    for(int i = 1; i <= n; ++i) {
        if(!cnt[i]) q.push(i);
    }
    while(q.size()) {
        int cur = q.front();
        q.pop();
        streak.push_back(cur);
        for(int &nxt : v[cur]) {
            --cnt[nxt];
            if(!cnt[nxt]) {
                q.push(nxt);
            }
        }
    }
    if(streak.size() != n) {
        cout << 0;
    }
    else {
        for(int &num : streak) {
            cout << num << '\n';
        }
    }
}
int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int num, prv;
        cin >> num >> prv;
        for(int j = 2; j <= num; ++j) {
            int tmp;
            cin >> tmp;
            ++cnt[tmp];
            v[prv].push_back(tmp);
            swap(prv, tmp);
        }
    }
    run();
}