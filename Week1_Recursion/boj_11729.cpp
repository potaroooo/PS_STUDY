#include <iostream>
using namespace std;
void hanoi(int n, int st, int via, int ed) {
    if(n == 1) {
        cout << '\n' << st << ' ' << ed;
        return;
    }
    hanoi(n - 1, st, ed, via);
    hanoi(1, st, via, ed);
    hanoi(n - 1, via, st, ed);
}

int main() {
    cin.tie(0);
    int n;
    cin >> n;
    cout << (1 << n) - 1;
    hanoi(n, 1, 2, 3);
}