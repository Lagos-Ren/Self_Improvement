#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	int x, y, z;
	cin >> x >> y;
	z = min(x, y);
	if (x > y)x -= y, y = 0;
	else y -= x, x = 0;
	cout << x * 60 + y * 40 + z * 90 << endl;
	return 0;
}