#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	int n, m, a[31];
	a[1] = 1, a[2] = 1;
	for (int i = 3; i <= 30; ++i)
		a[i] = a[i - 1] + a[i - 2];
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> m;
		cout << a[m] << endl;
	}
	return 0;
}