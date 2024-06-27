#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

double Num(int i) {
	return (i % 2 == 0) ? -1.0 / (double)i : 1.0 / (double)i;
}

int main() {
	int n;
	scanf("%d", &n);
	double S = 0.0;
	for (int i = 1; i <= n; ++i)
		S += Num(i);
	printf("%.4lf\n", S);
	return 0;
}