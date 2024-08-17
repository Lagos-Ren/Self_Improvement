#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

inline int Min_Base(int a, int b, int c) {
	int m = 0, n;
	while (a)n = a % 10, m = max(m, n), a /= 10;
	while (b)n = b % 10, m = max(m, n), b /= 10;
	while (c)n = c % 10, m = max(m, n), c /= 10;
	return m;
}

inline ll Convert_10(int n, int B) {
	ll m = 0, p = 0;
	while (n) {
//		if (!(n % 10)) { n /= 10; continue; }
		m += (n % 10) * (ll)pow((ll)B, p++);
		n /= 10;
	}
	return m;
}

inline bool Judge(int p, int q, int r, int B) {
	return Convert_10(p, B) * Convert_10(q, B) == Convert_10(r, B);
}

int main() {
	int p, q, r;
	cin >> p >> q >> r;
	int B = Min_Base(p, q, r) + 1;
	bool flag = false;
	for (int i = B; i <= 16; ++i)
		if (Judge(p, q, r, i)) {
			flag = true;
			cout << i << endl;
			break;
		}
	if (!flag)cout << "0" << endl;
	return 0;
}