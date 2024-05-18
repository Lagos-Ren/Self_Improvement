#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
using namespace std;

double mod(double a, double b) {
	double k = a / b;
	int c = (int)k;
	return a - (double)c * b;
}

int main() {
	double a, b;
	scanf("%lf %lf", &a, &b);
	printf("%.5lf\n", mod(a,b));
	return 0;
}