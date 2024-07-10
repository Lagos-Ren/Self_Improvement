#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

double Price[11] = { 0.0,28.9,32.7,45.6,78.0,35.0,86.2,27.8,43.0,56.0,65.0 };

int main() {
	double tot = 0.0;
	for (int a, i = 1; i <= 10; ++i) {
		scanf("%d", &a);
		tot += (double)a * Price[i];
	}
	printf("%.1lf\n", tot);
	return 0;
}