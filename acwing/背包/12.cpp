#include<iostream>
#include<vector>
using namespace std;
const int N = 1009;

int n, V;
int v[N];
int w[N];

int f[N][N];    // f[j]: 容量为j的最大价值
vector<int> g;  // 最大价值对应的物品编号

void input() {
    cin >> n >> V;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
}

void solve() {
    for (int i = n; i >= 1; i--) {      // 从n到1求最大价值，最大价值在f[1][V]
        for (int j = 0; j <= V; j++) {  
            f[i][j] = f[i+1][j];        
            if (j >= v[i])              // f[i][j]由f[i+1][j]转来
                f[i][j] = max(f[i][j], f[i+1][j - v[i]] + w[i]);
        }
    }
}

void getpath() {                        // 求字典序的编号，从1到n求
    for (int i = 1, j = V; i <= n; i++) {
        // 如果f[i][j]由f[i+1][j]转来，记录编号
        if (j >= v[i] && f[i][j] == f[i+1][j - v[i]] + w[i]) {
            g.push_back(i);
            j -= v[i];
        }
    }
}

void output() {
    for (int i = 0; i < g.size(); i++)
        cout << g[i] << " ";
}

int main() {
    input();
    solve();
    getpath();
    output();
    return 0;
}