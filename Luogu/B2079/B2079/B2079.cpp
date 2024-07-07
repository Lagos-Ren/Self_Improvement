#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;

inline ll Fac(ll n) {
	if (n == 0 || n == 1)return 1;
	else return n * Fac(n - 1);
}

int main() {
	ll n;
	scanf("%lld", &n);
	double e_ = 0.0;
	for (int i = 1; i <= n; ++i)
		e_ += 1.0 / (double)Fac(i);
	printf("%.10lf\n", e_ + 1);
	return 0;
}