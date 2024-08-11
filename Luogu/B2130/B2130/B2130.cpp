#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int a, b;
char c;

inline int Func(int a, int b, char c) {
	if (c == '+')return a + b;
	else if (c == '-')return a - b;
	else if (c == '*')return a * b;
	else if (c == '/')return a / b;
	else if (c == '%')return a % b;
	else return 0;
}

int main() {
	scanf("%d%c%d", &a, &c, &b);
	printf("%d\n", Func(a, b, c));
	return 0;
}