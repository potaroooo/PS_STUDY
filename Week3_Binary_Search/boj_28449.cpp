#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
int n, m, a_n[100'001], a_m[100'001];
ll res[3];

int l_bound(int *arr, int size, int val) { // val보다 작은 값 중에서 가장 큰 인덱스
    int ret = 0, left = 1, mid, right = size;
    while(left <= right) {
        mid = (left + right) / 2;
        if(arr[mid] >= val) {
            right = mid - 1;
        }
        else {
            if(mid > ret) ret = mid;
            left = mid + 1;
        }
    }
    return ret;
}

int u_bound(int *arr, int size, int val) { // val 보다 큰 값 중에서 가장 작은 인덱스
    int ret = size + 1, left = 1, mid , right = size;
    while(left <= right) {
        mid = (left + right) / 2;
        if(arr[mid] <= val) {
            left = mid + 1;
        }
        else {
            if(ret > mid) ret = mid;
            right = mid - 1;
        }
    }
    return ret;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; scanf("%d", &a_n[i]), ++i);
    sort(a_n + 1, a_n + 1 + n);
    for(int i = 1; i <= m; scanf("%d", &a_m[i]), ++i);
    sort(a_m + 1, a_m + 1 + m);

    for(int i = 1; i <= n; ++i) {
        int lb = l_bound(a_m, m, a_n[i]),
        ub = u_bound(a_m, m, a_n[i]);
        res[0] += lb, res[1] += m + 1 - ub, res[2] += ub - lb - 1;
    }

    printf("%lld %lld %lld\n", res[0], res[1], res[2]);
}