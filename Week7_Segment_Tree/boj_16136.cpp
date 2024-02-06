#include <iostream>
#include <cmath>
// #define DEBUG
using namespace std;
typedef long long ll;
constexpr int MX_N = 100'000;
constexpr int MX_A = 1'000'000;
typedef struct node {
    ll val;
    int mx;
} nd;

int N, Q, A[MX_A + 1], dividers_count[MX_A + 1] = {0, 1, };
nd sgt[MX_N * 4 + 5];
bool not_prime[MX_A + 1]{true, true,};

int get_dividers_count(int num) {
    int ret = 0;
    if(!not_prime[num]) return 2;
    for(int i = 1; i * i <= num; ++i) {
        if(num % i) continue;
        if(i != num / i) ret += 2;
        else ++ret;
    }
    return ret;
}

nd init(int node, int left, int right) {
    if(left == right) return sgt[node] = {A[left], A[left]};
    int mid = (left + right) / 2;
    nd l = init(node * 2, left, mid), r = init(node * 2 + 1, mid + 1, right);
    return sgt[node] = {
        l.val + r.val, max(l.mx, r.mx)
    };
}

void update(int node, int left, int right, int st, int ed) {
    if(ed < left || st > right) return;
    if(left == right) {
        if(!dividers_count[A[left]]) dividers_count[A[left]] = get_dividers_count(A[left]);
        A[left] = sgt[node].val = sgt[node].mx = dividers_count[A[left]];
        return;
    }
    int mid = (left + right) / 2;
    if(sgt[node * 2].mx > 2) update(node * 2, left, mid, st, ed);
    if(sgt[node * 2 + 1].mx > 2) update(node * 2 + 1, mid + 1, right, st, ed);
    sgt[node] = {
        sgt[node * 2].val + sgt[node * 2 + 1].val,
        max(sgt[node * 2].mx, sgt[node * 2 + 1].mx)
    };
}

ll get_sum(int node, int left, int right, int st, int ed) {
    if(st > right || ed < left) return 0LL;
    if(st <= left && right <= ed) return sgt[node].val;
    int mid = (left + right) / 2;
    return
    get_sum(node * 2, left, mid, st, ed) +
    get_sum(node * 2 + 1, mid + 1, right, st, ed);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> N >> Q;
    for(int i = 1; i <= N; cin >> A[i++]);
    for(int i = 2; i <= MX_A; ++i) {
        if(not_prime[i]) continue;
        dividers_count[i] = 2;
        for(int j = i * 2; j <= MX_A; j += i) {
            if(not_prime[j]) continue;
            not_prime[j] = true;
        }
    }
    init(1, 1, N);
    while(Q--) {
        int T, S, E;
        cin >> T >> S >> E;
        if(T & 1) {
            #ifdef DEBUG
            cout << "before update : \n";
            for(int i = S; i <= E; ++i) {
                cout << A[i] << ' ';
            }
            cout << '\n';
            #endif
            update(1, 1, N, S, E);
            #ifdef DEBUG
            cout << "after update : \n";
            for(int i = S; i <= E; ++i) {
                cout << A[i] << ' ';
            }
            cout << '\n';
            #endif
        }
        else {
            cout << get_sum(1, 1, N, S, E) << '\n';
            #ifdef DEBUG
            ll tsum = 0LL;
            for(int i = S; i <= E; ++i) {
                tsum += A[i];
                cout << A[i] << ' ';
            }
            cout << "tsum : " << tsum << '\n';
            #endif
        }
    }
}