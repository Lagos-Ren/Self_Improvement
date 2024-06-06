#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<iostream>
using namespace std;

int Judge(int n, int m) {
	return n >= 10 || m >= 20 ? 1 : 0;
}

int main() {
	int n, m;
	cin >> n >> m;
	cout << Judge(n, m) << endl;
	return 0;
}