#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>

int main() {
	int x;
	scanf("%d", &x);
	x == 0 ? putchar('0') : putchar('1');
	return 0;
}

/*
int main() {
	int x;
	scanf("%d", &x);
	printf("%d\n", (int)((bool)x));
	return 0;
}
*/