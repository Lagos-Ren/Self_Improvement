#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	int n, k, a, tot = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		if (a == k)tot++;
	}
	cout << tot << endl;
	return 0;
}