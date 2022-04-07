#include<iostream>
using namespace std;
const int N = 109;

int t;  // t组问题
int r;  // r行
int c;  // c列

int w[N][N];    // 花生个数
int f[N][N];    // f[i][j]: 走到(i, j)位置时采摘花生最大个数

void solve() {
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            // (i, j)可以从(i-1, j)走过来
            //      也可以从(i, j-1)过来
            f[i][j] = max(f[i-1][j], f[i][j-1]) + w[i][j];
        }
    }
    cout << f[r][c] << endl;
}

void input() {
    cin >> t;
    while (t--) {
        cin >> r >> c;
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                cin >> w[i][j];
        solve();
    }
}

int main() {
    input();
    return 0;
}