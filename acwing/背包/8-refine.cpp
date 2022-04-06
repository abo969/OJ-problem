#include<bits/stdc++.h>
using namespace std;
const int N = 1009;
const int M = 109;

int n;  // 物品个数
int V;  // 背包容积
int W;  // 背包重量

int f[M][M];    // f[i][j]：体积i、重量j是的最大价值

// 二维背包
void solve() {
    cin >> n >> V >> W;
    for (int i = 1; i <= n; i++) {
        int v, w, p;
        cin >> v >> w >> p;     // 体积、重量、价值

        for (int j = V; j >= v; j--) {   // 体积限制
            for (int k = W; k >= w; k--) // 重量限制
                f[j][k] = max(f[j][k], f[j-v][k-w] + p);
        }
    }
    cout << f[V][W] << endl;
}

int main() {
    solve();
    return 0;
}