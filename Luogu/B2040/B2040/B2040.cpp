#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>

int Judge(int n) {
	return n >= 10 && n <= 99 ? 1 : 0;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", Judge(n));
	return 0;
}