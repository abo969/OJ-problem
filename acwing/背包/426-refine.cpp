#include<iostream>
using namespace std;
const int N = 30;
const int M = 30009;

int n;          // 希望买的物品数量
int V;          // 总钱数

int v[N];       // v[i]：每个物品价格
int w[N];       // w[i]：每个物品重要度

int f[M];       // f[j]: 花费为j的最大价值

void input() {
    cin >> V >> n;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
}

// 01背包
void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = V; j >= 1; j--) {
            if (j >= v[i])          // 第i个物品可以装进去
                f[j] = max(f[j], f[j-v[i]] + v[i] * w[i]);
        }
    }
    cout << f[V] << endl;
}

int main() {
    input();
    solve();
    return 0;
}