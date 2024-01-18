#include <iostream>
#include <algorithm>
using namespace std;

constexpr int N = 1'000;
int n, a[N + 1], cnt[N + 1], sum;

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    int min_idx = 1, mlt_idx = 1;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
        ++cnt[a[i]];
        if(a[i] < a[min_idx]) min_idx = i;
        if(cnt[a[i]] * a[i] > cnt[a[mlt_idx]] * a[mlt_idx]) mlt_idx = i;
    }
    sum += a[mlt_idx] * cnt[a[mlt_idx]];
    swap(a[1], a[min_idx]);
    sort(a + 2, a + 1 + n, [](const int& x, const int& y) {
        return x >= y;
    });
    cout << sum << '\n';
    for(int i = 1; i <= n; ++i) {
        cout << a[i] << ' ';
    }
}