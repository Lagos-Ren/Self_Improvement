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

inline int Get_Prime(int n) {
	if (is_Prime(n))return n;
	else {
		for (int i = n; i >= 2; --i)
			if (!(n % i) && is_Prime(i))return i;
	}
}

int main() {
	int m, n;
	cin >> m >> n;
	for (int i = m; i <= n; ++i) {
		cout << Get_Prime(i);
		if (i < n)cout << ",";
		else cout << endl;
	}
	return 0;
}