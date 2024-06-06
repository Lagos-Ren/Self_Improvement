#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<iostream>
using namespace std;

int Judge(int n) {
	return (n % 3) || (n % 5);
}

int main() {
	int n;
	cin >> n;
	if (!Judge(n))cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}