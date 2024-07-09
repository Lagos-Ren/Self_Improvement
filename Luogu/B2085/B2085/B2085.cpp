#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

inline bool Is_Prime(int n) {
	for (int i = 3; i <= sqrt(n); i+=2)
		if (!(n % i))return false;
	return true;
}

int main() {
	int n;
	cin >> n;
	if (n == 1)cout << "2" << endl;
	else {
		int i, j;
		for (i = 3, j = 2; j <= n; i += 2)
			if (Is_Prime(i))j++;
		cout << i - 2 << endl;
	}
	return 0;
}