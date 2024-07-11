#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	int n, a[5];
	memset(a, 0, sizeof(a));
	scanf("%d", &n);
	for (int m, i = 1; i <= n; ++i) {
		scanf("%d", &m);
		if (0 <= m && m <= 18)a[1]++;
		else if (18 < m && m <= 35)a[2]++;
		else if (35 < m && m <= 60)a[3]++;
		else if (m > 60)a[4]++;
	}
	for (int i = 1; i <= 4; ++i) {
		double rt = (double)a[i] / (double)n;
		printf("%.2lf%%\n", rt * 100.0);
	}
	return 0;
}