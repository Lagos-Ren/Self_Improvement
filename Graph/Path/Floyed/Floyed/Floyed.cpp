#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define INF 0x3f3f3f3f
#define N 114
int A[N][N], path[N][N];
int n, m, s;

int main() {
	int u, v, w;
	cin >> n >> m >> s;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			A[i][j] = i == j ? 0 : INF;
			path[i][j] = -1;
		}
	}
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v >> w;
		A[u][v] = min(A[u][v], w);
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (A[i][j] > A[i][k] + A[k][j])
					A[i][j] = A[i][k] + A[k][j], path[i][j] = k;
	for (int i = 1; i <= n; ++i) {
		if (A[s][i] < INF)cout << A[s][i];
		else cout << 0x7fffffff;
		if (i < n)cout << " ";
	}
	cout << endl;
	return 0;
}