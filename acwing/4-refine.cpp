#include<iostream>
using namespace std;
const int N = 1009;

int n, V;       // 个数、背包容积
int v[N];       // 体积
int w[N];       // 价值
int c[N];       // 数量
int f[N];       // f[j]：容量为j的最大价值

void input() {
    cin >> n >> V;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i] >> c[i];
}

// 多重背包
/*
  f[i][j] = max(f[i-1][j- k * v[i]] + k * w[i])
  k = 0, 1, 2, ..., c[i]
 */
void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = V; j >= 0; j--) {
            for (int k = 0; k <= c[i]; k++) {
                if (k * v[i] <= j)
                    f[j] = max(f[j], f[j- k* v[i]] + k * w[i]);
            }
        }
    }
    
    cout << f[V] << endl;
}

int main() {
    input();
    solve();
    return 0;
}