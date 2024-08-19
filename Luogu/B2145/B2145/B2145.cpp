#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

inline int digit(int n, int k) {
	int p;
	while (k--)p = n % 10, n /= 10;
	return p;
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << digit(n, k) << endl;
	return 0;
}