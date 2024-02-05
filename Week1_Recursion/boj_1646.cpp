#include <iostream>
// #define DEBUG
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int n;
ll st, ed, dp[51]{1, 1};
//          i
// i - 2          i - 1

int get_child_node(int node, ll pos) {
    if(pos == 1) return node;
    if(pos <= 1 + dp[node - 2]) return node - 2;
    else return node - 1;
}

int get_child_depth(int child_node, ll child_pos) {
    if(child_pos == 1) return 1;
    int l = child_node - 2, r = child_node - 1;
    if(child_pos <= 1 + dp[l]) return 1 + get_child_depth(l, child_pos - 1);
    else return 1 + get_child_depth(r, child_pos - 1 - dp[l]); 
}

void rec(int node, ll st, ll ed) {
    if(node < 0 || st == ed) return; // 도착
    int st_node = get_child_node(node, st),
    ed_node = get_child_node(node, ed);
    #ifdef DEBUG
    cout << "node, st_node, ed_node : " << node << ' ' << st_node << ' ' << ed_node << '\n';
    #endif
    if(st_node == ed_node) { // 같은 경우
        if(st_node == node - 2) rec(node - 2, st - 1, ed - 1);
        else 
            rec(node - 1, st - 1 - dp[node - 2], ed - 1 - dp[node - 2]);
        return;
    }
    else { // 다른 경우
        if(st_node != node) {
            if(st_node == node - 2)
                cout << string(get_child_depth(st_node, st - 1), 'U');// 출발점이 속한 노드를 루트 노드까지 끌어올림
            else
                cout << string(get_child_depth(st_node, st - 1 - dp[node - 2]), 'U');
            st_node = node;
        }
        if(st_node == ed_node) return; // 도착점이 루트 노드였던 경우
        if(ed_node == node - 2) { // 도착점이 좌측 노드였던 경우
            cout << 'L';
            rec(node - 2, 1, ed - 1);
        }
        else { // 도착점이 우측 노드였던 경우
            cout << 'R';
            rec(node - 1, 1, ed - 1 - dp[node - 2]);
        }
        return;
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> st >> ed;
    for(int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] + 1;
        #ifdef DEBUG
        cout << "dp[i] : " << i << ' ' << dp[i] << ' ';
        #endif
    }
    rec(n, st, ed);
}