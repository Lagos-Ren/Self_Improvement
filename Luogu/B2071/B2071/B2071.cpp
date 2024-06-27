#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

inline int gcd(int a, int b, int c) {
	if (a == 1 || b == 1 || c == 1)return 1;
	int n = max(a, max(b, c));
	for (int i = 2; i <= n; ++i)
		if ((a % i) == (b % i) && (b % i) == (c % i))return i;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << gcd(a, b, c) << endl;
	return 0;
}