#include <iostream>
using namespace std;
typedef long long ll;
ll total[51] = {1, };
ll patty[51] = {1, };
ll n, x;
ll layer(ll lv, ll eat) {
    // 기저사례 1
    if(lv == 0) return 1; // 레벨 0 버거는 패티만 존재
    if(eat <= 1) return 0; // 1장 이하는 패티를 먹을 수 없다
    if(eat >= total[lv]) return patty[lv];  // 현재 레벨 햄버거의 분량 이상 먹은 경우(완식) -> 해당 레벨 버거가 갖는 패티만큼 먹게 됨
    // 1장 초과, 중간 패티 직전까지
    if(eat <= 1 + total[lv - 1]) return layer(lv - 1, eat - 1);
    // 중간 패티까지 먹음
    if(eat == 2 + total[lv - 1]) return patty[lv - 1] + 1;
    // 중간 패티보다 많이 먹은 경우
    if(eat > 2 + total[lv - 1]) return patty[lv - 1] + 1 + layer(lv - 1, eat - (2 + total[lv - 1]));
}
int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> x;
    for(ll l = 1; l <= n; ++l) {
        total[l] = 3 + 2 * total[l - 1];
        patty[l] = 1 + 2 * patty[l - 1];
    }
    cout << layer(n, x);
}