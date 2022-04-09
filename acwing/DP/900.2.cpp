#include<iostream>
using namespace std;
const int N = 1009;
const int MOD = 1e9 + 7;

int n;          // 正数n
int f[N];       // f[j]: 前j个数和为j的方案数

/*
  完全背包思想
  f(j)：1 ~ i 共i个数，每个数有无限多，背包体积恰好为j, 方案数
  因此，f(j) = f(j) + f(j-i)
  最后方案数为 f(n)
 */
void solve() {
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            f[j] = (f[j] + f[j-i]) % MOD;
        }
    }
    cout << f[n] << endl;
}

int main() {
    cin >> n;
    solve();
    return 0;
}