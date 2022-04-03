#include<iostream>
using namespace std;
const int V = 1009;
const int M = 109;

int T;          // 总时间
int m;          // 草药数目
int t[M];       // t[i]:采第i种草药时间
int v[M];       // v[i]:第i种草药的价值
int f[V];       // f[j]:时间为j的最大价值

void input() {
	cin >> T >> m;
	for (int i = 1; i <= m; i++) cin >> t[i] >> v[i];
}

// 01背包
void solve() {
    for (int i = 1; i <= m; i++) {
        for (int j = T; j >= t[i]; j--) {
            f[j] = max(f[j], f[j - t[i]] + v[i]);
        }
    }
}

int main() {
    input();
    solve();
	cout << f[T] << endl;
	return 0; 
}