#include <iostream>
#include <vector>
using namespace std;
#define up first
#define down second
constexpr int MX = 500'000;
typedef pair<int, int> pii;

int N;
pii k[MX + 1], sum[MX + 1];

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cin >> N;
    for(int i = 1, num; i <= N; ++i) {
        cin >> num;
        if(num > 0) ++k[num].up;
        else ++k[-num].down;
    }
    for(int i = 1; i <= N; ++i) { // i - 1명 이하의 인원이 거짓말했다고 한 사람의 수를 구함
        sum[i].down = sum[i - 1].down + k[i - 1].down;
    }
    for(int i = N - 1; i >= 0; --i) { // i + 1명 이상의 인원이 거짓말했다고 한 사람의 수를 구함
        sum[i].up = sum[i + 1].up + k[i + 1].up;
    }
    vector<int> ans;
    for(int i = 0; i <= N; ++i) {
        if(sum[i].up + sum[i].down == i) // sum[i]의 up과 down의 합이 i와 같다면 i명이 거짓말을 할 수 있다
            ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for(const int &num : ans)
        cout << num << ' ';
}