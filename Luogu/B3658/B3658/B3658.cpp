#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	float x, y;
	cin >> x >> y;
	cout << (int)floor(x / y) << endl;
	return 0;
}