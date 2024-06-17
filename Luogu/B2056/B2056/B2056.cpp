#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;

int main() {
	int n, a;
	ll ans = 0;
	double aver;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a);
		ans += a;
	}
	aver = (double)ans / (double)n;
	printf("%lld %.5lf\n", ans, aver);
	return 0;
}