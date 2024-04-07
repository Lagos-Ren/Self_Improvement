#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%.3lf%%\n",((double)b*100/(double)a));
	return 0;
}