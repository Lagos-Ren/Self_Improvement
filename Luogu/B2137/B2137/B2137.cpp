#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

inline bool is_Prime(int n) {
	if (n == 0 || n == 1)return false;
	if (n == 2 || n == 3)return true;
	if (!(n % 2))return false;
	for (int i = 3; i <= sqrt(n); i += 2)
		if (!(n % i))return false;
	return true;
}

int main() {
	int a, b, tot = 0;
	cin >> a >> b;
	if (a > b)swap(a, b);
	for (int i = a; i <= b; ++i)
		if (is_Prime(i))tot++;
	cout << tot << endl;
	return 0;
}