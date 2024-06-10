#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int Cul(int x, char ch) {
	if (x <= 1000)return ch == 'y' ? 13 : 8;
	x -= 1000;
	int y = x / 500;
	x %= 500;
	if (x)return ch == 'y' ? 13 + 4 * (y + 1) : 8 + 4 * (y + 1);
	else return ch == 'y' ? 13 + 4 * y : 8 + 4 * y;
}

int main() {
	int x;
	char ch;
	cin >> x >> ch;
	cout << Cul(x, ch) << endl;
	return 0;
}