#include <iostream>
using namespace std;
int n;
string str[64];
void qt(int l, int u, int sz) {
    bool flag = true;
    for(int i = l; i < l + sz; ++i)
        for(int j = u; j < u + sz; ++j)
            if(str[i][j] != str[l][u]) {
                flag = false;
                break;
            }
    if(flag) {
        cout << str[l][u];
        return;
    }
    int hf = sz >> 1;
    cout << '(';
    qt(l, u, hf);
    qt(l, u + hf, hf);
    qt(l + hf, u, hf);
    qt(l + hf, u + hf, hf);
    cout << ')';
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> str[i];
    qt(0, 0, n);
}