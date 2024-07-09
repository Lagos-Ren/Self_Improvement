#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

inline bool Judge(int a, int b, int c, int x, int y) {
	return (a * x + b * y) == c ? true : false;
}

int main() {
	int a, b, c, tot = 0;
	cin >> a >> b >> c;
	for (int i = 0; i <= c; ++i)
		for (int j = 0; j <= c; ++j)
			if (Judge(a, b, c, i, j))tot++;
	cout << tot << endl;
	return 0;
}