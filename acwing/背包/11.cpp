#include<iostream>
using namespace std;
const int N = 1009;
const int MOD = 1e9 + 7;
int n, V;
int v[N];
int w[N];

int f[N];    // f[j]: 容量为j的最大价值
int g[N];    // g[j]: 最大价值对应的方案数

void input() {
    cin >> n >> V;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    for (int i = 0; i <= V; i++) g[i] = 1;  // 初始化，从0开始
}

void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = V; j >= v[i]; j--) {
            int value = f[j-v[i]] + w[i];   // 选第i个物品的价值
            if (f[j] < value) {     // 如果选第i个物品后价值更大
                f[j] = value;       // 更新f[j]
                g[j] = g[j-v[i]];   // 方案数应该为g[j-v[i]]
            } else if (f[j] == value) {
                // 否则，f[j]不变，总方案数加上g[j-v[i]
                g[j] = (g[j] + g[j-v[i]]) % MOD;
            }
        }
    }

    cout << g[V] << endl;
}

int main() {
    input();
    solve();
    return 0;
}