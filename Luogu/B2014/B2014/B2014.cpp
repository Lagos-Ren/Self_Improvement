#define _CRT_SECURE_NO_WARNINGS 1
#define PI 3.14159
#include<cstdio>

int main() {
	double r;
	scanf("%lf", &r);
	double d = r * 2.0;
	printf("%.4lf %.4lf %.4lf\n", d, d * PI, PI * r * r);
	return 0;
}