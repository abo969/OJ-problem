#include<iostream>
using namespace std;
const int N = 1009;
const int MOD = 1e9 + 7;

int n;          // 正数n
int f[N][N];    // f[i][j]: j个数和为i的方案数

/*
  f(i, j)：分为两种：A：j个数里最小值为1，B：j个数里最小值>1
  A：将最小值1去掉，为j-1个数，但和为i-1
  B：将每个数减1，仍为j个数，但和为i-j
  因此，f(i, j) = f(i-1, j-1) + f(i-j, j)
 */
void solve() {
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {  // 对和为i来说，最多i个1相加，所以j<=i
            f[i][j] = (f[i-1][j-1] + f[i-j][j]) % MOD;
        }
    }
}

void output() {
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = (ans + f[n][i]) % MOD;
    cout << ans << endl;
}

int main() {
    cin >> n;
    solve();
    output();
    return 0;
}