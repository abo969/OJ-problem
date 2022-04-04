#include<iostream>
using namespace std;
const int N = 1009;

int n, V;
int v[N];
int w[N];
int f[N];    // f[j]：容量为j的最大价值

void input() {
    cin >> n >> V;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
}

// 完全背包
void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = v[i]; j <= V; j++) {
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