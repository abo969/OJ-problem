#include<iostream>
using namespace std;
const int N = 1009;

int n, V;
int v[N];
int w[N];
int f[N][N];    // f[i][j]：前i个物品容量为j的最大价值

void input() {
    cin >> n >> V;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
}

// 完全背包
void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= V; j++) {
            f[i][j] = f[i-1][j];
            if (j >= v[i])  // 第i个物品能装进j的容量里
                f[i][j] = max(f[i][j], f[i][j-v[i]] + w[i]);
        }
    }
    
    cout << f[n][V] << endl;
}

int main() {
    input();
    solve();
    return 0;
}