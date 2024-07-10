#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 114;
int a[N];

int main() {
	int n, m, tot = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	cin >> m;
	for (int i = 1; i <= n; ++i)
		if (a[i] == m)tot++;
	cout << tot << endl;
	return 0;
}