#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define ll long long
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
	int n, m = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		if (is_Prime(i))Prime[++m] = i;
	ll maxn = 0;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= m; ++j)
			if (Prime[i] + Prime[j] == n)maxn = max(maxn, (ll)Prime[i] * Prime[j]);
	cout << maxn << endl;
	return 0;
}