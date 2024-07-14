#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 303;
int n;
double num[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lf", &num[i]);
	sort(num + 1, num + 1 + n);
	double tot = 0.0;
	for (int i = 2; i < n; ++i)
		tot += num[i] / (double)(n - 2);
	double mis = max(abs(num[2] - tot), abs(num[n - 1] - tot));
	printf("%.2lf %.2lf\n", tot, mis);
	return 0;
}