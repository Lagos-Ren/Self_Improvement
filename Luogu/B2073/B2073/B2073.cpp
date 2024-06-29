#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	int a, b, n;
	cin >> a >> b >> n;
	if (a == b)cout << "0" << endl;
	else {
		for (int i = 1; i <= n && a; ++i) {
			a %= b;
			a *= 10;
		}
		cout << a / b << endl;
	}
	return 0;
}