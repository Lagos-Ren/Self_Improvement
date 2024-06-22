#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

inline int Power(int a, int n) {
	return n == 0 ? 1 : a * Power(a, n - 1);
}

int main() {
	int a, n;
	cin >> a >> n;
	cout << Power(a, n) << endl;
	return 0;
}