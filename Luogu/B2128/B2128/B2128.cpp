#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

inline bool is_Prime(int n) {
	if (n == 0 || n == 1)return false;
	if (n == 2 || n == 3)return true;
	if (!(n % 2))return false;
	for (int i = 3; i < n - 1; i += 2)
		if (!(n % i))return false;
	return true;
}

int main() {
	int n, tot = 0;
	cin >> n;
	for (int i = 2; i <= n; ++i)
		if (is_Prime(i))tot++;
	cout << tot << endl;
	return 0;
}