#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 114514;
int n, a, maxn = 0;
int coun[N] = { 0 };

int main() {
	memset(coun, 0, sizeof(coun));
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		coun[a]++, maxn = max(maxn, a);
	}
	for (int i = 0; i <= maxn; ++i)
		cout << coun[i] << endl;
	return 0;
}