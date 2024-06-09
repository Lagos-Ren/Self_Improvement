//60pts(TLE)
#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;

int n, m;
long long tot = 0;
bool a[21][21] = { false };

inline void walk(int x, int y) {
	if (a[x][y])return;
	if (x == n && y == m) { tot++; return; }
	if (x < n)walk(x + 1, y);
	if (y < m)walk(x, y + 1);
	return;
}

int main() {
	int xx, yy;
	cin >> n >> m >> xx >> yy;
	a[xx][yy] = 1;
	a[xx - 1][yy - 2] = 1, a[xx - 1][yy + 2] = 1;
	a[xx - 2][yy - 1] = 1, a[xx - 2][yy + 1] = 1;
	a[xx + 1][yy - 2] = 1, a[xx + 1][yy + 2] = 1;
	a[xx + 2][yy - 1] = 1, a[xx + 2][yy + 1] = 1;
	walk(0, 0);
	cout << tot << endl;
	return 0;
}