#include <iostream>
using namespace std;
constexpr int MX = 1'000;

int T, n, bt_pre[MX + 1], bt_in[MX + 1];

void print_bt_post(int pre_st, int pre_ed, int in_st, int in_ed) {
    if(pre_st > pre_ed) return;
    if(pre_st == pre_ed) {
        cout << bt_pre[pre_st] << ' ';
        return;
    }
    int l_cnt = 0;
    for(int i = in_st; i <= in_ed; ++i) {
        if(bt_in[i] == bt_pre[pre_st]) break;
        ++l_cnt;
    }
    print_bt_post(pre_st + 1, pre_st + l_cnt, in_st, in_st + l_cnt); // 좌측 자식 노드
    print_bt_post(pre_st + l_cnt + 1, pre_ed, in_st + l_cnt + 1, in_ed); // 우측 자식 노드
    cout << bt_pre[pre_st] << ' ';
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 1; i <= n; cin >> bt_pre[i++]);
        for(int i = 1; i <= n; cin >> bt_in[i++]);
        print_bt_post(1, n, 1, n);
        cout << '\n';
    }
}