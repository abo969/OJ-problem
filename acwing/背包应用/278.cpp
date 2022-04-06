#include<iostream>
using namespace std;
const int N = 109;
const int M = 10009;

int n;      // 数字个数
int m;      // 数字的和
int v[N];   // 数字

int f[M];   // f[j]：和为j的最大价值
int g[M];   // g[j]：最大价值对应的方案数

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i];
    // 初始化方案数数组全为1，且从0开始
    for (int i = 0; i <= m; i++) g[i] = 1;
}

void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= v[i]; j--) {
            int value = f[j - v[i]] + v[i]; // 选第i个数的价值
            if (f[j] < value) {             // 如果选第i个数后价值更大
                f[j] = value;               // 此时最大价值应该为value
                g[j] = g[j - v[i]];         // 此时方案数应该为g[j-v[i]]
            } else if (f[j] == value) {     // 否则
                g[j] += g[j - v[i]];        // 方案数加上g[j-v[i]]
            }
        }
    }

    cout << g[m] << endl;
}

int main() {
    input();
    solve();
    return 0;
}