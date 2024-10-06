#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;

const int N = 55;
int n, m;
int dis[N][N];
ll b[N][N];

inline void Init() {
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			b[i][j] = dis[i][j] = 0;
	return;
}

inline int Cul(int x, int y, int i, int j) {
	return (x - i) * (x - i) + (y - j) * (y - j);
}

int main() {
	Init();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> b[i][j];
	for (int x = 1; x <= n; ++x) {
		for (int y = 1; y <= m; ++y) {
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= m; ++j) {
					if (x == i && y == j)continue;
					if (b[x][y] == b[i][j])
						dis[x][y] = max(dis[x][y], Cul(x, y, i, j));
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			cout << dis[i][j] << " ";
		cout << endl;
	}
	return 0;
}