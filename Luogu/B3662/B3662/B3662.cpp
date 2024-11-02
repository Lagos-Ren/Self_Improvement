#define _CRT_SECURE_NO_WARNINGS 1 
#include<cmath>
#include<cstdio>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1002;
int n, m, T, a[N][N];
inline bool Judge(int x, int y) {
	bool flag = true;
	if (x > 0)
		if (a[x - 1][y] >= a[x][y])flag = false;
	if (y > 0)
		if (a[x][y - 1] >= a[x][y])flag = false;
	if (x < n - 1)
		if (a[x + 1][y] >= a[x][y])flag = false;
	if (y < m - 1)
		if (a[x][y + 1] >= a[x][y])flag = false;
	return flag;
}

int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &a[i][j]);
	scanf("%d", &T);
	int x, y, u, v, k = 0;
	while (T--) {
		scanf("%d %d %d %d", &x, &y, &u, &v);
		swap(a[x - 1][y - 1], a[u - 1][v - 1]);
	}
	vector<int>Local;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (Judge(i, j))k++, Local.push_back(i + 1), Local.push_back(j + 1);
	printf("%d\n", k);
	for (int i = 0; i < k; ++i)
		printf("%d %d\n", Local[i * 2], Local[i * 2 + 1]);
	return 0;
}