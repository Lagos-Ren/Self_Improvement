#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;

const int N = 114;
int n, m, k;
int A[N][N], B[N][N];
ll C[N][N];

inline ll Cul(int i, int j) {
	ll ans = 0;
	for (int p = 1; p <= m; ++p)
		ans += (A[i][p] * B[p][j]);
	return ans;
}

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> A[i][j];
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= k; ++j)
			cin >> B[i][j];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= k; ++j)
			C[i][j] = Cul(i, j);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}