#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int MAXN = 1e6 + 7;
int n, layer;
int t[MAXN] = { 0 };
long long m, ans[MAXN] = { 0 };

int main() {
	int l = 0, r = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> t[i];
	for (int i = 1; i <= n; i*=2) {
		l++;
		for (int j = 1; j <= i; ++j) {
			ans[l] += t[i + j - 1];
		}
		if (ans[l] > m)m = ans[l], layer = l;
	}
	cout<< layer << endl;
	return 0;
}