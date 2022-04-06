#include<iostream>
using namespace std;
const int N = 30;
const int M = 30009;

int n;          // 希望买的物品数量
int V;          // 总钱数

int v[N];       // v[i]：每个物品价格
int w[N];       // w[i]：每个物品重要度

int f[N][M];    // f[i][j]: 前i个物品花费为j的最大价值

void input() {
    cin >> V >> n;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
}

void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= V; j++) {
            f[i][j] = f[i-1][j];    // 不买第i个物品
            if (j >= v[i])          // 第i个物品可以装进去
                f[i][j] = max(f[i-1][j], f[i-1][j-v[i]] + v[i] * w[i]);
        }
    }
    cout << f[n][V] << endl;
}

int main() {
    input();
    solve();
    return 0;
}