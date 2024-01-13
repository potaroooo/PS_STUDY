#include <iostream>
using namespace std;
typedef long long ll;
constexpr ll MOD = 1'000'000'007;

typedef struct matrix {
    ll m[2][2] {
        {1, 1},
        {1, 0}
    };

    void print() {
        printf("%lld\n", m[0][1]);
    }

} mat;

mat mat_mult(mat a, mat b) {
    mat c{};
    c.m[0][0] = (a.m[0][0] * b.m[0][0] + a.m[0][1] * b.m[1][0]) % MOD;
    c.m[0][1] = (a.m[0][0] * b.m[0][1] + a.m[0][1] * b.m[1][1]) % MOD;
    c.m[1][0] = (a.m[1][0] * b.m[0][0] + a.m[1][1] * b.m[1][0]) % MOD;
    c.m[1][1] = (a.m[1][0] * b.m[0][1] + a.m[1][1] * b.m[1][1]) % MOD;
    return c;
}
mat mat_fib(mat a, ll t) {
    if(t == 1) {
        return mat{};
    }
    mat tmp = mat_fib(a, t / 2);
    tmp = mat_mult(tmp, tmp);
    if(t & 1) tmp = mat_mult(tmp, mat{});
    return tmp;
}

int main() {
    ll n;
    scanf("%lld", &n);
    mat ans = mat_fib(mat {}, n);
    ans.print();
}