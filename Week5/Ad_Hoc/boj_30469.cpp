#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    
    string a, b;
    int n;
    cin >> a >> b >> n;
    n -= 4;
    // a 뒷자리 -> 1 3 7 9
    // b 앞자리가 -> 2 4 5 6 8? 불가능
    switch(b[0]) {
            case '2' :
            case '4' :
            case '5' :
            case '6' :
            case '8' :
                cout << -1;
                return 0;
            default :
                if(a[1] == '9') {
                    cout << a + '7' + string(n - 1, '1') + b;
                }
                else {
                    cout << a + string(n, '1') + b;
                }
    }
}