#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

inline int Hermite(int n, int x) {
	if (!n)return 1;
	else if (n == 1)return 2 * x;
	else return 2 * x * Hermite(n - 1, x) - 2 * (n - 1) * Hermite(n - 2, x);
}

int main() {
	int n, x;
	cin >> n >> x;
	cout << Hermite(n, x) << endl;
	return 0;
}