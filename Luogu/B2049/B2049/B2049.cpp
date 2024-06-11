#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << max(a, max(b, c)) << endl;
	return 0;
}