#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
string s1 = "Messi Gimossi", s2 = "Messi Messi Gimossi";
vector<ll> dp;
ll m;
void run(ll pos, int cur) {
    if(pos <= 13) {
        if(s1[pos - 1] == ' ') cout << s2;
        else cout << s1[pos - 1];
        return;
    }
    if(pos <= dp[cur - 1]) {
        run(pos, cur - 1);
        return;
    }
    else if(pos == dp[cur - 1] + 1) {
        cout << s2;
        return;
    }
    else {
        run(pos - dp[cur - 1] - 1, cur - 2);
        return;
    }
}
int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    dp.push_back(-1);
    dp.push_back(5);
    dp.push_back(13);
    cin >> m;
    while(true) {
        int sz = dp.size();
        int val = dp[sz - 1] + 1 + dp[sz - 2];
        if(val <= 0) break;
        dp.push_back(val);
    }
    for(int i = (int) dp.size() - 1; i >= 1; --i) {
        if(m <= dp[i]) {
            run(m, i);
            break;
        }
    }
}