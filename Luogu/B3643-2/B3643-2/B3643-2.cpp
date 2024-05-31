#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int n, m;
bool g[1001][1001];

int main() {
	memset(g, false, sizeof(g));
	cin >> n >> m;
	int u, v;
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v;
		g[u][v] = true, g[v][u] = true;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (g[i][j])cout << "1";
			else cout << "0";
			if (j != n)cout << " ";
		}
		cout << endl;
	}
	for (int i = 1; i <= n; ++i) {
		int ans = 0;
		for (int j = 1; j <= n; ++j)
			if (g[i][j])ans++;
		if (!ans)cout << ans;
		else {
			cout << ans << " ";
			for (int j = 1; j <= n; ++j)
				if (g[i][j])cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}