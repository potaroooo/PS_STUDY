#include <iostream>
using namespace std;
int N, K;

void print_sep(int cur_bit, int count_left) {
    if(cur_bit <= 0 || count_left <= 0) return;
    int cur_count = 1 << (cur_bit - 1);
    if(cur_count <= count_left) {
        print_sep(cur_bit - 1, count_left - cur_count);
        int mn = 1 << (cur_bit - 1),
        mx = 1 << cur_bit;
        for(; mn < mx; ++mn)
            cout << mn << ' ';
    }
    else print_sep(cur_bit - 1, count_left); 
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> N >> K;
    cout << "YES\n";
    if(K == 1 << N) {
        for(int i = 0; i < K; ++i)
            cout << i << ' ';
        return 0;
    }
    print_sep(N, K);
}