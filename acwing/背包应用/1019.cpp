#include<bits/stdc++.h>
using namespace std;
const int N = 509;
const int M = 6009;

int n;          // 奖品种类
int m;          // 拨款金额
int p[N];       // 第i种奖品价格
int v[N];       // 第i种奖品价值
int s[N];       // 第i种奖品数量
int f[N][M];    // f[i][j]: 前i种奖品用j的拨款金额的最大价值

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> p[i] >> v[i] >> s[i];
}

// 庆功会：多重背包
void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {  // 拨款数量j
            for (int k = 0; k <= s[i]; k++) {
                if (k * p[i] <= j)      // 第i个奖品选k个
                    f[i][j] = max(f[i][j], f[i-1][j-k*p[i]] + k*v[i]);
            }
        }
    }
    cout << f[n][m] << endl;
}

int main() {
    input();
    solve();
    return 0;
}