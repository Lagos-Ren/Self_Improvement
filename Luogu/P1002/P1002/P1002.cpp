#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;

const int N = 24;
int bx, by, mx, my;
ll f[N][N];
bool M[N][N];

int main() {
	cin >> bx >> by >> mx >> my;
	for (int i = 0; i <= bx; ++i)f[0][i] = 1;
	M[mx][my] = true;
	M[mx - 2][my - 1] = M[mx - 2][my + 1] = true;
	M[mx - 1][my - 2] = M[mx - 1][my + 2] = true;
	M[mx + 1][my - 2] = M[mx + 1][my + 2] = true;
	M[mx + 2][my - 1] = M[mx + 2][my + 1] = true;
	for (int i = 0; i <= bx; ++i) {
		for (int j = 0; j <= by; ++j) {
			if (M[i][j]) {
				f[i][j] = 0;
				continue;
			}
			if ((!i) && (!j))continue;
			if (!i)f[i][j] = f[i][j - 1];
			else if (!j)f[i][j] = f[i - 1][j];
			else f[i][j] = f[i - 1][j] + f[i][j - 1];
		}
	}
	cout << f[bx][by] << endl;
	return 0;
}

/*
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
*/