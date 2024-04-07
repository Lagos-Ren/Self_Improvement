#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>

int main() {
	int x, a, y, b;
	scanf("%d %d %d %d", &x, &a, &y, &b);
	printf("%.2lf\n",(double)(x*a-y*b)/(double)(a-b));
	return 0;
}