#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>

int main() {
	double a;
	scanf("%lf", &a);
	printf("%f\n%.5f\n%e\n%g\n", a, a, a, a);
	return 0;
}