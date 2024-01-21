#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

string operation[]{
    "A+=A\n",
    "A+=B\n",
    "B+=A\n",
    "B+=B\n"
};
ll a, b;
vector<int> ans;

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> a >> b;
    while(!(a & 1)) {
        a >>= 1;
        ans.push_back(3);
    }
    while(!(b & 1)) {
        b >>= 1;
        ans.push_back(0);
    }

    while(a != b) {
        if(a > b) {
            a += b;
            ans.push_back(1);
        }
        else {
            b += a;
            ans.push_back(2);
        }
        while(!(a & 1)) {
            a >>= 1;
            ans.push_back(3);
        }
        while(!(b & 1)) {
            b >>= 1;
            ans.push_back(0);
        }
    }

    cout << ans.size() << '\n';
    for(const int &i : ans) {
        cout << operation[i]; 
    }
}