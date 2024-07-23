#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 114;
int n, m, A[N][N], B[N][N];

inline int Cul(int i, int j) {
	if (i == 1 || j == 1 || i == n || j == m)return A[i][j];
	else {
		int ans = (A[i][j] + A[i - 1][j] + A[i + 1][j] + A[i][j - 1] + A[i][j + 1]) / 5;
		double ans_ = double(A[i][j] + A[i - 1][j] + A[i + 1][j] + A[i][j - 1] + A[i][j + 1]) / 5.0;
		double dec = ans_ - (double)ans;
		return dec >= 0.5 ? ans + 1 : ans;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> A[i][j];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			B[i][j] = Cul(i, j);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			cout << B[i][j] << " ";
		cout << endl;
	}
	return 0;
}