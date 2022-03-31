#include<iostream>
using namespace std;
const int N = 20;
const int M = 20;

int n;          // n个公司
int m;          // m台设备
int v[N][M];    // v[i][j]：第i家公司分j台设备的盈利

int f[N][M];    // f[i][j]：前i家公司分j台设备的最大盈利
int g[N];       // g[i]：第i家公司分配的机器台数

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> v[i][j];
}

// 多重背包思想
void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {      // m台设备相当于背包体积
            //f[i][j] = f[i-1][j];
            for (int k = 0; k <= j; k++) {  // 枚举第i家公司分配k台设备
                f[i][j] = max(f[i][j], f[i-1][j-k] + v[i][k]);
            }
        }
    }
}

void getpath(int i, int j) {
    if (i == 0) return;
    
    for (int k = 0; k <= j; k++) {
        // 如果f[i][j]由f[i-1][j-k]转来
        if (f[i][j] == f[i-1][j-k] + v[i][k]) {
            g[i] = k;           // 第i家公司分配k台机器
            getpath(i-1, j-k);  // 递归寻找前一个路径：i-1，还剩j-k台机器
            return;
        }
    }
}

void output() {
    cout << f[n][m] << endl;
    for (int i = 1; i <= n; i++)
        cout << i << " " << g[i] << endl;
}

int main() {
    input();
    solve();
    getpath(n, m);
    output();
    return 0;
}
