#include <iostream>
#include <vector>
using namespace std;

string ipt, bomb;
vector<char> stk;

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> ipt >> bomb;
    if(bomb.length() > ipt.length()) {
        cout << ipt;
        return 0;
    }
    if(bomb == ipt) {
        cout << "FRULA";
        return 0;
    }
    for(int i = 0; i < ipt.length(); ++i) {
        stk.push_back(ipt[i]);
        if(stk.back() == bomb.back() && stk.size() >= bomb.length()) {
            int size_dif = (int)(stk.size() - bomb.length());
            for(int idx = (int)bomb.length() - 1; idx >= 0; --idx) {
                int ipt_idx = size_dif + idx;
                if(stk[ipt_idx] != bomb[idx]) break;
                if(idx == 0) {
                    for(int t = bomb.length(); t; --t) stk.pop_back();
                }
            }
        }
    }
    if(stk.empty())
        cout << "FRULA";
    else {
        for(char &c : stk)
            cout << c;
    }
}