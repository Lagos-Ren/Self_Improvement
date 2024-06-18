#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	int n, a, maxn = -1;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		if (a > maxn)maxn = a;
	}
	cout << maxn << endl;
	return 0;
}