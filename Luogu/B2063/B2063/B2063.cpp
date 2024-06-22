#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define RT 1e-3
using namespace std;

double Cul(int x, int n) {
	if (!n)return (double)x;
	double ans = (double)x;
	for (int i = 1; i <= n; ++i)
		ans = ans * (1.0 + RT);
	return ans;
}

int main() {
	int x, n;
	scanf("%d %d", &x, &n);
	printf("%.4lf\n", Cul(x, n));
	return 0;
}