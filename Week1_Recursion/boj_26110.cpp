#include <iostream>
using namespace std;
string ipt;
bool pal(int left, int right, int cnt) {
    if(left >= right) return true;
    if(ipt[left] == ipt[right]) {
        return pal(left + 1, right - 1, cnt);
    }
    if(cnt > 0) {
        return pal(left + 1, right, cnt - 1) | pal(left, right - 1, cnt - 1);
    }
    return false;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> ipt;
    for(int i = 0; i <= 3; ++i) {
        if(pal(0, (int)ipt.length() - 1, i)) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}