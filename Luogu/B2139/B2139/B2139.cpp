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

inline bool is_TruePrime(int n) {
	int m = 0, a = 0, num[10];
	memset(num, 0, sizeof(num));
	while (n)num[++a] = n % 10, n /= 10;
	for (int i = 1; i <= a; ++i)
		m = m * 10 + num[i];
	return is_Prime(m);
}

int main() {
	int m, n;
	bool flag = false;
	cin >> m >> n;
	for (int i = m; i <= n; ++i) {
		if (is_Prime(i)) {
			if (is_TruePrime(i)) {
				if (flag)cout << ",";
				flag = true;
				cout << i;
			}
		}
	}
	if (!flag)cout << "No" << endl;
	return 0;
}