#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	int n, age, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &age);
		ans += age;
	}
	double aver = (double)ans / (double)n;
	printf("%.2lf\n", aver);
	return 0;
}