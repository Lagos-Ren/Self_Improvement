#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

inline double Get_m(int a, int b, int c) {
	return double(max(a, max(b, c))) / (double(max(a + b, max(b, c))) * double(max(a, max(b, b + c))));
}

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%.3lf\n", Get_m(a, b, c));
	return 0;
}