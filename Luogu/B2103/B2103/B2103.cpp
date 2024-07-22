#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 114;
int n, m, S, ans = 0;
int A[N][N], b;

int main() {
	cin >> m >> n;
	S = n * m;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%d", &A[i][j]);
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &b);
			if (b == A[i][j])ans++;
		}
	}
	printf("%.2lf\n", double(ans) * 100.0 / double(S));
	return 0;
}