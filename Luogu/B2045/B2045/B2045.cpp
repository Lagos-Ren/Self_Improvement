#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<iostream>
using namespace std;

bool Judge(int n) {
	return (n == 1) || (n == 3) || (n == 5);
}

int main() {
	int n;
	cin >> n;
	if (Judge(n))cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}