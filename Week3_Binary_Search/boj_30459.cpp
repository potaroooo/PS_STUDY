#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, a[2'001], b[40'001];
double r, ans = -1;

int main() {
    scanf("%d %d %lf", &n, &m, &r);
    for(int i = 1; i <= n; scanf("%d", &a[i]), ++i);
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= m; scanf("%d", &b[i]), ++i);
    sort(b + 1, b + 1 + m);
    
    for(int i = 1; i < n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            int v = a[j] - a[i];
            int left = 1, mid, right = m;
            while(left <= right) {
                mid = (left + right) / 2;
                double tmp = b[mid] * v / 2.0;
                if(tmp > r) {
                    right = mid - 1;
                }
                else {
                    if(tmp > ans) ans = tmp;
                    left = mid + 1;
                }
            }
        }
    }
    ans < 0 ? printf("-1") : printf("%.1lf", ans);
}
