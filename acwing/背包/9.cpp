#include<bits/stdc++.h>
using namespace std;
const int N = 109;
const int M = 109;

int G;              // 组数
int V;              // 背包容量
int v[N][N];        // v[i][j]：第i组第j个物品体积
int w[N][N];        // w[i][j]：第i组第j个物品价值
int s[N];           // s[i]：第组物品个数

int f[N][M];        // f[i][j]：前i组物品容积j时的最大值

void input() {
    cin >> G >> V;
    for (int i = 1; i <= G; i++) {
        cin >> s[i];     // 第i组物品数量
        for (int j = 0; j < s[i]; j++) {
            cin >> v[i][j] >> w[i][j];
        }
    }
}

// 分组背包
void solve() {
    for (int i = 1; i <= G; i++) {
        for (int j = 0; j <= V; j++) {
            f[i][j] = f[i-1][j];                // 第组物品都不选
            for (int k = 0; k < s[i]; k++) {    // 枚举第i组物品
                if (j >= v[i][k])               // 选第i组第k个物品
                    f[i][j] = max(f[i][j], f[i-1][j - v[i][k]] + w[i][k]);
            }
        }
    }
    
    cout << f[G][V] << endl;
}

int main() {
    input();
    solve();
    return 0;
}
