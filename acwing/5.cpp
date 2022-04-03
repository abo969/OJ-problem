#include<iostream>
using namespace std;
const int N = 25009;
const int M = 2009;

int n, V;       // 个数、背包容积
int v[N];       // 体积
int w[N];       // 价值
int f[M];       // f[j]：前i个物品容量为j的最大价值

int cnt = 1;    // 拆分后的总个数

// 输入的同时进行二进制拆分
void input() {
    cin >> n >> V;
    for (int i = 1; i <= n; i++) {
        int vi, wi, si;
        cin >> vi >> wi >> si;
        
        // 拆分
        int k = 1;
        while (k <= si) {
            v[cnt] = k * vi;    // k个物品的体积（k个物品重新打包为一个物品的体积）
            w[cnt++] = k * wi;  // k个物品的价值
            si -= k;
            k *= 2;             // 二进制拆分：1、2、4、8、...
        }
        
        // 剩下的自成一组
        if (si > 0) {
            v[cnt] = si * vi;   // 剩余物品的体积
            w[cnt++] = si * wi; // 剩余物品的价值
        }
    }
    
    n = cnt;                    // 重新打包后物品总个数
}

// 多重背包，但数据量大
/*
  f[i][j] = max(f[i-1][j- k * v[i]] + k * w[i])
  k = 0, 1, 2, ..., c[i]
  拆分后变成01背包问题
 */
void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = V; j >= v[i]; j--) {
            f[j] = max(f[j], f[j-v[i]] + w[i]);
        }
    }
    cout << f[V] << endl;
}

int main() {
    input();
    solve();
    return 0;
}