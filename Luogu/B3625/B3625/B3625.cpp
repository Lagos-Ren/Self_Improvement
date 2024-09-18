#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 114;
int n, m;
bool flag = false, f[N][N];

inline void DFS(int x, int y) {
	if (x<1 || y<1 || x>n || y>m || !f[x][y] || flag)return;
	if (x == n && y == m) {
		flag = true;
		return;
	}
	f[x][y] = false;
	DFS(x - 1, y);
	DFS(x, y - 1);
	DFS(x + 1, y);
	DFS(x, y + 1);
	return;
}

int main() {
	cin >> n >> m;
	char ch;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			f[i][j] = false;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> ch;
			if (ch == '.')f[i][j] = true;
		}
	}
	DFS(1, 1);
	flag ? cout << "Yes" << endl : cout << "No" << endl;
	return 0;
}

/*
//BFS(RE 0pts)
const int N = 114;
int n, m;
bool flag = false, f[N][N];

struct Node {
	int x, y;
}Q[11451];
int l, r;

inline void Init() {
	l = r = 1;
	for (int i = 0; i <= n + 1; ++i)
		for (int j = 0; j <= m + 1; ++j)
			f[i][j] = false;
	return;
}

inline void Visit(int x, int y) {
	f[x][y] = false;
	if (x == n && y == m)flag = true;
	return;
}

inline void EnQueue(int x, int y) {
	Q[r].x = x, Q[r].y = y;
	r++;
	return;
}

inline void DeQueue(int& x, int& y) {
	x = Q[l].x, y = Q[l].y;
	l++;
	return;
}

inline void BFS(int x,int y) {
	EnQueue(x, y);
	int i, j;
	while (l != r) {
		DeQueue(i, j);
		if (i<1 || j<1 || i>n || j>m)continue;
		Visit(i, j);
		if (flag)break;
		if (i - 1 >= 1 && f[i - 1][j])EnQueue(i - 1, j);
		if (j - 1 >= 1 && f[i][j - 1])EnQueue(i, j - 1);
		if (i + 1 <= n && f[i + 1][j])EnQueue(i + 1, j);
		if (j + 1 <= m && f[i][j + 1])EnQueue(i, j + 1);
	}
	return;
}

int main() {
	Init();
	cin >> n >> m;
	char ch;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> ch;
			if (ch == '.')f[i][j] = true;
		}
	}
	BFS(1, 1);
	flag ? cout << "Yes" << endl : cout << "No" << endl;
	return 0;
}
*/