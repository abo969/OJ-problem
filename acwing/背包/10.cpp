#include<iostream>
#include<vector>
using namespace std;
const int N = 109;

int n;              // 物品个数
int V;              // 背包体积

int v[N];           // 物品体积
int w[N];           // 物品价值

int root;           // 根节点编号
vector<int> e[N];   // 邻接表保存树

int f[N][N];        // f[u][j]：以u为根的子树体积不超过j的最大价值

void input() {
    cin >> n >> V;
    for (int i = 1; i <= n; i++) {
        int p;      // 依赖的父节点的编号
        cin >> v[i] >> w[i] >> p;
        if (p == -1) root = i;
        else //add(p, i);
            e[p].push_back(i);
    }
}

// 分组背包
void dfs(int u) {
    for (int i = 0; i < e[u].size(); i++) {     // 枚举物品组
        int c = e[u][i];                        // c为u的儿子节点
        dfs(c);

        for (int j = V - v[u]; j >= 0; j--) {   // 枚举体积
            for (int k = 0; k <= j; k++)        // 决策
                f[u][j] = max(f[u][j], f[u][j-k] + f[c][k]);
        }
    }
    
    for (int j = V; j >= v[u]; j--)             // 将物品u装进背包
        f[u][j] = f[u][j - v[u]] + w[u];

    for (int i = 0; i < v[u]; i++) f[u][i] = 0;
}

int main() {
    input();
    dfs(root);
    cout << f[root][V] << endl;
    return 0;
}
