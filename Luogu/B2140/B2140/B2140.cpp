#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

inline bool Judge(int n) {
	int m = 0, B[13];
	while (n)B[m++] = n % 2, n /= 2;
	int n_0 = 0, n_1 = 0;
	for (int i = 0; i < m; ++i)
		!B[i] ? n_0++ : n_1++;
	return n_1 > n_0;
}

inline void Work(int n) {
	int a = 0, b = 0;
	for (int i = 1; i <= n; ++i)
		Judge(i) ? a++ : b++;
	cout << a << " " << b << endl;
	return;
}

int main() {
	int n;
	cin >> n;
	Work(n);
	return 0;
}