#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void test(int x) {
	x = 1024;
	printf("test�����ڲ� x=%d\n", x);
	return;
}

int main() {
	int x = 1;
	printf("����testǰ x=%d\n", x);
	test(x);
	printf("����test�� x=%d\n", x);
	return 0;
}