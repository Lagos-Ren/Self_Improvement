#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int cul(int x, int y, char ch) {
	if (ch == '+')return x + y;
	else if (ch == '-')return x - y;
	else if (ch == '*')return x * y;
	else if (ch == '/')return x / y;
}

bool Judge_ch(char ch) {
	return (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') ? true : false;
}

int main() {
	int x, y;
	char ch;
	cin >> x >> y >> ch;
	if (!Judge_ch(ch))cout << "Invalid operator!" << endl;
	else if (ch == '/' && y == 0)cout << "Divided by zero!" << endl;
	else cout << cul(x, y, ch) << endl;
	return 0;
}