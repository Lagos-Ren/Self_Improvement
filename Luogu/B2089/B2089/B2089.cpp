#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 114;

int main() {
	int n,a[N];
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = n; i >= 1; --i)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}