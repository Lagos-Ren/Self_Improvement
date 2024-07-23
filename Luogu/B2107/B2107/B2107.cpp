#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 114;
int n, m, A[N][N];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> A[i][j];
	for (int i = 1; i <= m; ++i) {
		for (int j = n; j >= 1; --j)
			cout << A[j][i] << " ";
		cout << endl;
	}
	return 0;
}