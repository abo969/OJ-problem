#include<bits/stdc++.h>
using namespace std;
const int N = 1009;
const int M = 109;

int n;  // 物品个数
int V;  // 背包容积
int W;  // 背包重量

int v[N];   // 体积v[i]
int w[N];   // 重量w[i]
int p[N];   // 价值p[i]

int f[N][N];    // f[i][j]：体积i、重量j是的最大价值

void input() {
    cin >> n >> V >> W;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i] >> p[i];
}

// 二维背包
void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = V; j >= v[i]; j--) {   // 体积限制
            for (int k = W; k >= w[i]; k--) // 重量限制
                f[j][k] = max(f[j][k], f[j-v[i]][k-w[i]] + p[i]);
        }
    }
    cout << f[V][W] << endl;
}

int main() {
    input();
    solve();
    return 0;
}