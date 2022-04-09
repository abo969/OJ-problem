#include<iostream>
using namespace std;
const int N = 1009;
const int MOD = 1e9 + 7;

int n;          // 正数n
int f[N][N];    // f[i][j]: 前i个数和为j的方案数

/*
  完全背包思想
  f(i, j)：1 ~ i 共i个数，每个数有无限多，背包体积恰好为j, 方案数
  i分别选0个， 1个，2个，...，s个, s = j/i, 共s+1项
  f(i, j) = f(i-1, j) + f(i-1, j-i) + f(i-1, j-2*i) + ... + f(i-1, j-s*i)
  用j-i替换j，得到, 保证j-s*i>=0,因此替换后只有s项
  f(i, j-i) = f(i-1, j-i) + f(i-1, j-2*i) + ... + f(i-1, j-s*i)

  因此，f(i, j) = f(i-1, j) + f(i, j-i)
  最后方案数为 f(n, n)
 */
void solve() {
    f[0][0] = 1; // f[0][1] = f[1][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {  // 对和为i来说，最多i个1相加，所以j<=i
            f[i][j] = f[i-1][j];
            if (j >= i)
                f[i][j] = (f[i-1][j] + f[i][j-i]) % MOD;
        }
    }
    cout << f[n][n] << endl;
}

int main() {
    cin >> n;
    solve();
    return 0;
}