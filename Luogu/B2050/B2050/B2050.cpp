#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int Judge(int a, int b, int c) {
	return ((a + b) > c) && ((a + c) > b) && ((b + c) > a) ? 1 : 0;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << Judge(a, b, c) << endl;
	return 0;
}