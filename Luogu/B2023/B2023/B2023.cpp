#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>

int main() {
	char a;
	int b;
	float c;
	double d;
	scanf("%c %d %f %lf", &a, &b, &c, &d);
	printf("%c %d %.6f %.6lf\n", a, b, c, d);
	return 0;
}