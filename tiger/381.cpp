#include <iostream>
#include <vector>
using namespace std;
const int N = 1009;
const int M = 3009;
const int C = 3;

int n; // 物品数量
int V; // 背包体积

/*
  因每个主件只有0、1、2个附件，且如果买主件，就必须买附件
  考虑将该附件和其主件重新打包为一个新的物品
*/
vector<int> w[N]; // w[i]：第i个物品组第j个物品体积
vector<int> v[N]; // w[i]：第i个物品组第j个物品价值

int f[M]; // f[i][j]: 前i个物品组体积为j的最大价值

void input()
{
    cin >> V >> n;
    for (int i = 1, j = 0; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (i % C == 1)
            j++; // j为主件编号
        w[j].push_back(x);
        v[j].push_back(y);
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
void init()
{
    for (int i = 1; i <= n; i++)
    {
        if (w[i].size() > 2)
        { // 有2个附件，计算x b的价值
            // 将x a b这个组合放进分组，同时计算x a b的价值
            w[i].push_back(w[i][1] + w[i][2]);
            v[i].push_back(v[i][1] + v[i][2]);
        }

        // 修改 x a、x b的体积
        for (int j = 1; j < w[i].size(); j++)
        {
            w[i][j] += w[i][0];
            v[i][j] += v[i][0];
        }
    }
}

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        if (w[i].size() == 0)
            continue;

        for (int j = V; j >= 0; j--)
        {
            for (int k = 0; k < w[i].size(); k++)
            {                     // 枚举第i组物品
                if (j >= w[i][k]) // 选第i组第k个物品
                    f[j] = max(f[j], f[j - w[i][k]] + v[i][k]);
            }
        }
    }
    cout << f[V] << endl;
}

int main()
{
    input();
    init();
    solve();
    return 0;
}