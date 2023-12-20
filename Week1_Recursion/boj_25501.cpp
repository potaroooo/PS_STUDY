#include <iostream>
using namespace std;
int tc, cnt;
string ipt;
bool pal(int l, int r) {
    ++cnt;
    if(l >= r) 
        return true;
    if(ipt[l] != ipt[r])
        return false;
    return pal(l + 1, r - 1);
}
int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> tc;
    while(tc > 0) {
        --tc;
        cin >> ipt;
        cout << (pal(0, (int)ipt.size() -1) ? 1 : 0) << ' ' << cnt << '\n';
        cnt = 0;
    }
}