#include <iostream>
using namespace std;

string yes = "";

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        yes += "yes\n";
    cout << yes;
}