#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 10086;
int Prime[N];

inline bool is_Prime(int n) {
	if (n == 0 || n == 1)return false;
	if (n == 2 || n == 3)return true;
	if (!(n % 2))return false;
	for (int i = 3; i <= sqrt(n); i += 2)
		if (!(n % i))return false;
	return true;
}

int main() {
	int n, tail = 0;
	cin >> n;
	if (n < 5)cout << "empty" << endl;
	else {
		for (int i = 1; i <= n; ++i)
			if (is_Prime(i))Prime[++tail] = i;
		for (int i = 2; i <= tail; ++i)
			if ((Prime[i] - Prime[i - 1]) == 2)
				cout << Prime[i - 1] << " " << Prime[i] << endl;
	}
	return 0;
}