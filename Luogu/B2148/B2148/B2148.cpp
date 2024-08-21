#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

inline double Func(double x, double n) {
	if (n == 1.0)return x / (1.0 + x);
	else return x / (n + Func(x, n - 1.0));
}

int main() {
	double x, n;
	scanf("%lf %lf", &x, &n);
	printf("%.2lf\n", Func(x, n));
	return 0;
}