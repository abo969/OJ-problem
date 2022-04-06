#include<iostream>
using namespace std;
const int C = 1009;
const int M = 29;
const int N = 90;
const int INF = 1e9;

int m;      // 氧需要的量
int n;      // 氮需要的量
int K;      // 气缸数量
int a[C];   // a[i]: 第i个气缸的氧量
int b[C];   // b[i]: 第i个气缸的氮量
int c[C];   // c[i]: 第i个气缸的重量

int f[M][N];    // f[j][k]: 氧气量j、氮气量k，气缸重量最小值

void input() {
    cin >> m >> n >> K;
    for (int i = 1; i <= K; i++)
        cin >> a[i] >> b[i] >> c[i];

    for (int j = 0; j < N; j++)
        for (int i = 0; i < M; i++)
            f[i][j] = INF;  // 求最小值，初始化我INF
    f[0][0] = 0;            // 求最小值, f(0,0)初始化为0
}

void solve() {
    for (int i = 1; i <= K; i++)            // 枚举气缸
        for (int j = m; j >= 0; j--)        // 氧气量限制
            for (int k = n; k >= 0; k--) {  // 氮气量限制
                int x = max(0, j - a[i]);
                int y = max(0, k - b[i]);
                f[j][k] = min(f[j][k], f[x][y] + c[i]);
            }
    cout << f[m][n] << endl;
}

int main() {
    input();
    solve();
    return 0;
}