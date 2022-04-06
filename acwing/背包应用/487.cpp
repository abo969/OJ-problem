#include<iostream>
#include<vector>
using namespace std;
const int N = 65;
const int M = 32009;

int n;          // 希望买的物品数量
int V;          // 总钱数

/*
  因每个主件只有0、1、2个附件，且如果买主件，就必须买附件
  考虑将该附件和其主件重新打包为一个新的物品
*/
vector<int> p[N];   // p[i]：第i个物品组第j个物品价格
vector<int> w[N];   // w[i]：第i个物品组第j个物品重要度
                    // 重要度数组主要用来计算价值
vector<int> v[N];   // v[i]：第i组物品每个物品的价值=p[i]*w[i]
                    // 如果有附件的，将附件一起算进来

int f[M];           // f[i][j]: 前i个物品组花费为j的最大价值

void input() {
    cin >> V >> n;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c == 0) {   // 如果该物品是主件，主件总是在第0个位置
            p[i].push_back(a);
            w[i].push_back(b);
            v[i].push_back(a * b);
        } else {        // 如果该物品是附件
            p[c].push_back(a);
            w[c].push_back(b);
            v[c].push_back(p[c][0] * w[c][0] + a * b);
        }
    }
}

// 将附件和主件重新打包
/*
  假设x物品有两个附件a、b，那么重新打包可能有以下几种组合
  其中，如果有两个附件，前面3种组合已经在p、v数组里了
  x
  x a
  x b
  x a b
  如果有两个附件，需要计算第4种组合，并加入该组
  同时重新计算加上附件后的价格、价值
*/
void init() {
    for (int i = 1; i <= n; i++) {
        if (p[i].size() == 0) continue;
        
        if (p[i].size() > 2) {  // 有2个附件，计算x b的价值
            // 将x a b这个组合放进分钟，同时计算x a b的价值
            p[i].push_back(p[i][1] + p[i][2]);
            v[i].push_back(v[i][0] + p[i][1] * w[i][1] + p[i][2] * w[i][2]);
        }
    
        // 修改 x a、x b的价格
        for (int j = 1; j < p[i].size(); j++)
            p[i][j] += p[i][0];
    }
}

void solve() {
    for (int i = 1; i <= n; i++) {
        if (p[i].size() == 0) continue;
        
        for (int j = V; j >= 0; j--) {
            for (int k = 0; k < p[i].size(); k++) { // 枚举第i组物品
                if (j >= p[i][k])                   // 选第i组第k个物品
                    f[j] = max(f[j], f[j-p[i][k]] + v[i][k]);
            }
        }
    }
    cout << f[V] << endl;
}

int main() {
    input();
    init();
    solve();
    return 0;
}