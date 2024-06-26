#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

inline bool Judge(int d) {
	int a = d / 1000; d -= a * 1000;
	int b = d / 100; d -= b * 100;
	int c = d / 10; d -= c * 10;
	return d - a - b - c > 0 ? true : false;
}

int main() {
	int n, a, tot = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		if (Judge(a))tot++;
	}
	cout << tot << endl;
	return 0;
}