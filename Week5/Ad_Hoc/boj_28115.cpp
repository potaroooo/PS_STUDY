#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    
    int n;
    cin >> n;
    int a[n + 1];
    cin >> a[1];
    if(n > 1) cin >> a[2];
    for(int i = 3, d1 = a[2] - a[1]; i <= n; ++i) {
        cin >> a[i];
        int d2 = a[i] - a[i - 1];
        if(d1 != d2) {
            cout << "NO"; 
            return 0;
        }
        d1 = d2;
    }
    cout << "YES\n";
    for(int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    cout << '\n';
    for(int i = 1; i <= n; ++i)
        cout << "0 ";
}