#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

bool Judge(int x, int y) {
	return (x >= -1) && (x <= 1) && (y >= -1) && (y <= 1) ? true : false;
}

int main() {
	int x, y;
	cin >> x >> y;
	if (Judge(x, y))cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}