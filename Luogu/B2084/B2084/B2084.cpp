#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

inline bool is_Prime(int n) {
	if (n == 1 || !n)return false;
	if (n == 2)return true;
	for (int i = 2; i <= sqrt(n); ++i)
		if (!(n % i))return false;
	return true;
}

int main() {
	int n;
	cin >> n;
	if (!(n % 2))cout << n / 2 << endl;
	else {
		int i;
		for (i = 3; i <= sqrt(n); ++i)
			if (!(n % i) && is_Prime(i))break;
		cout << n / i << endl;
	}
	return 0;
}