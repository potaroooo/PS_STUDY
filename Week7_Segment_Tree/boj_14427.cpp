#include <iostream>
// #define DEBUG
using namespace std;
constexpr int N = 100'001;
constexpr int INF = 2'100'000'000;

int n, a[N], sgt[N * 4 + 1];

int init(int node = 1, int left = 0, int right = n - 1) {
    if(left == right) {
        return sgt[node] = left;
    }
    int mid = (left + right) / 2;
    int l = init(node * 2, left, mid),
    r = init(node * 2 + 1, mid + 1, right);
    if(a[l] == a[r]) {
        return sgt[node] = l < r ? l : r;
    }
    else
        return sgt[node] = a[l] < a[r] ? l : r;
}

void update(int index, int node = 1, int left = 0, int right = n - 1) {
    if(index < left || index > right || left == right) return;
    int mid = (left + right) / 2;
    update(index, node * 2, left, mid);
    update(index, node * 2 + 1, mid + 1, right);
    int l = sgt[node * 2], r = sgt[node * 2 + 1];
    if(a[l] < a[r]) {
        if(a[l] == a[sgt[node]])
            sgt[node] = sgt[node] < l ? sgt[node] : l;
        else 
            sgt[node] = a[sgt[node]] < a[l] ? sgt[node] : l;
    }
    else if(a[r] < a[l]) {
        if(a[r] == a[sgt[node]])
            sgt[node] = sgt[node] < r ? sgt[node] : r;
        else 
            sgt[node] = a[sgt[node]] < a[r] ? sgt[node] : r;
    }
    else {
        int m = l < r ? l : r;
        if(a[m] == a[sgt[node]])
            sgt[node] = sgt[node] < m ? sgt[node] : m;
        else 
            sgt[node] = a[sgt[node]] < a[m] ? sgt[node] : m;
    }
    return;
}

int query(int node = 1, int left = 0, int right = n - 1, int st = 0, int ed = n - 1) {
    if(st > right || ed < left) return n;
    if(st <= left && right <= ed) {
        return sgt[node];
    }
    int mid = (left + right) / 2;
    int l = query(node * 2, left, mid, st, ed),
    r = query(node * 2 + 1, mid + 1, right, st, ed);
    if(a[l] < a[r]) {
        if(a[l] == a[sgt[node]])
            return sgt[node] < l ? sgt[node] : l;
        else 
            return a[sgt[node]] < a[l] ? sgt[node] : l;
    }
    else if(a[r] < a[l]) {
        if(a[r] == a[sgt[node]])
            return sgt[node] < r ? sgt[node] : r;
        else 
            return a[sgt[node]] < a[r] ? sgt[node] : r;
    }
    else {
        int m = l < r ? l : r;
        if(a[m] == a[sgt[node]])
            return sgt[node] < m ? sgt[node] : m;
        else 
            return a[sgt[node]] < a[m] ? sgt[node] : m;
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; cin >> a[i++]);
    a[n] = INF;
    init();
    int m;
    cin >> m;
    while(m--) {
        int cmd;
        cin >> cmd;
        if(cmd & 1) {
            int ai, v;
            cin >> ai >> v;
            a[--ai] = v;
            update(ai);
        }
        else {
            #ifdef DEBUG
            cout << "answer : ";
            #endif
            cout << query() + 1 << '\n';
        }
    }   
}