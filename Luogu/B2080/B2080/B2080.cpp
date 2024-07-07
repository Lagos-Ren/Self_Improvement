#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

inline double Power(double x, int n) {
	if (n == 0)return 1.0;
	double ans = 1.0;
	for (int i = 1; i <= n; ++i)ans *= x;
	return ans;
//	return n == 0 ? 1.0 : x * Power(x, n - 1);
}

inline double Cul(double x, int n) {
	return (1.0 - Power(x, n + 1)) / (1.0 - x);
}

int main() {
	double x;
	int n;
	scanf("%lf %d", &x, &n);
	printf("%.2lf\n", Cul(x, n));
	return 0;
}