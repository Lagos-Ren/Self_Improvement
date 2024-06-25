#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	int n, m, a, tot = 0;
	cin >> m >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		if (m - a >= 0)m -= a;
		else { tot++; continue; }
	}
	cout << tot << endl;
	return 0;
}