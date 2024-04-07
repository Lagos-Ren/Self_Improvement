#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>

double cul(double r1, double r2) {
	return 1.0 / (1.0 / r1 + 1.0 / r2);
}

int main() {
	double a, b;
	scanf("%lf %lf", &a, &b);
	printf("%.2lf\n", cul(a, b));
	return 0;
}