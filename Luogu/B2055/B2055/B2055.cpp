#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	int n;
	double a, ans = 0.0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lf", &a);
		ans += a;
	}
	ans = ans / (double)n;
	printf("%.4lf\n", ans);
	return 0;
}