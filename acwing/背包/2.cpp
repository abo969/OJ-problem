#include<iostream>
using namespace std;
const int N = 1009;
int n, V;
int v[N];
int w[N];
int f[N][N];    // f[i][j]: 前i个物品容量为j的最大价值

void input() {
    cin >> n >> V;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
}

// 01背包
void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= V; j++) {
            f[i][j] = f[i-1][j];    // 第i个物品不装进去
            if (j >= v[i])          // 第i个物品可以装进去
                f[i][j] = max(f[i-1][j], f[i-1][j-v[i]] + w[i]);
        }
    }
    cout << f[n][V] << endl;
}

int main() {
    input();
    solve();
    return 0;
}