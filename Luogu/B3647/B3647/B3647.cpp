#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define INF 0x3f3f3f3f
using namespace std;

const int N = 105;
int n, m;
int mp[N][N];

int main() {
	cin >> n >> m;
	int u, v, w;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			mp[i][j] = INF;
		mp[i][i] = 0;
	}
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v >> w;
		mp[u][v] = mp[v][u] = min(mp[u][v], w);
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			cout << mp[i][j] << " ";
		cout << endl;
	}
	return 0;
}