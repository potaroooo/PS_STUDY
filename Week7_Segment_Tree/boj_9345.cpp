#include <iostream>
#include <cmath>
#include <algorithm>
// #define DEBUG
using namespace std;
constexpr int MX = 100'001;
constexpr int PINF = 2'100'000'000;
constexpr int NINF = -PINF;

typedef struct shelf {
    int min = PINF;
    int max = NINF;
} sf;

int pos[MX + 1];
sf arr[(MX << 2) + 1];
sf init(int node, int left, int right) {
    if(left == right) {
        return arr[node] = {left, right};
    }
    int mid = (left + right) / 2;
    sf l = init(node * 2, left, mid),
    r = init(node * 2 + 1, mid + 1, right);
    return arr[node] =
    {
        min(l.min, r.min),
        max(l.max, r.max)
    };
}

void update(int node, int left, int right, int index) {
    if(index < left || index > right) return;
    if(left == right) {
        arr[node] = {
            pos[index],
            pos[index]
        };
        return;
    }
    int mid = (left + right) / 2;
    update(node * 2, left, mid, index);
    update(node * 2 + 1, mid + 1, right, index);
    arr[node] = {
        PINF,
        NINF
    };
    sf chld = {
        min(arr[node * 2].min, arr[node * 2 + 1].min),
        max(arr[node * 2].max, arr[node * 2 + 1].max)
    };
    arr[node] = {
        min(arr[node].min, chld.min),
        max(arr[node].max, chld.max)
    };
    return;
}

sf query(int node, int left, int right, int st, int ed) {
    if(st > right || ed < left) return {PINF, NINF};
    if(st <= left && right <= ed) return arr[node];
    int mid = (left + right) / 2;
    sf l = query(node * 2, left, mid, st, ed),
    r = query(node * 2 + 1, mid + 1, right, st, ed);
    return {
        min(l.min, r.min),
        max(l.max, r.max)
    };
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--) {
        int N, K;
        cin >> N >> K;
        for(int i = 0, j = (N << 2) + 1; i <= j; ++i) {
            if(i <= N) {
                pos[i] = i;
            }
            arr[i] = {
                PINF,
                NINF
            };
        }
        init(1, 0, N - 1);
        while(K--) {
            int Q, A, B;
            cin >> Q >> A >> B;
            if(Q) {
                sf ans = query(1, 0, N - 1, A, B);
                #ifdef DEBUG
                cout << "query for A, B : " << A << ' ' << B << '\n';
                cout << "min, max : " << ans.min << ' ' << ans.max << '\n';
                #endif
                if(ans.min == A && ans.max == B ||
                ans.min == B && ans.max == A) cout << "YES\n";
                else cout << "NO\n";
            }
            else {
                #ifdef DEBUG
                cout << "Before Update : \n";
                for(int i = 0; i < N; ++i) {
                    cout << pos[i] << ' ';
                }
                cout << "Update for " << A << ' ' << B << '\n';
                cout << "Swapped " << pos[A] << ' ' << pos[B] << '\n';
                cout << '\n';
                #endif
                swap(pos[A], pos[B]);
                update(1, 0, N - 1, A);
                update(1, 0, N - 1, B);
                #ifdef DEBUG
                cout << "After Update : \n";
                for(int i = 0; i < N; ++i) {
                    cout << pos[i] << ' ';
                }
                cout << '\n';
                #endif
            }
        }
    }
}