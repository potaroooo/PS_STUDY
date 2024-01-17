#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    
    string ipt;
    cin >> ipt;
    
    int ans = -1, left = 0, right = (int)ipt.length() - 1;
    bool same = ipt[left] == ipt[right];
    while(left <= right) {
        if(ipt[0] != ipt[left] || ipt[0] != ipt[right])
            same = false;
        if(ipt[left] != ipt[right]) {
            cout << ipt.length();
            return 0;
        }
        ++left, --right;
    }
    if(same) cout << -1;
    else cout << (int)ipt.length() - 1;
}