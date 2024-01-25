#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int judge(int,int,int);

int main() {
	int a, b, c;
	for (a = 100; a <= 333; ++a) {
		b = a * 2, c = a * 3;
		if (judge(a, b, c))printf("%d %d %d\n", a, b, c);
	}
	return 0;
}

int judge(int a, int b, int c) {
	int sum[10] = { 0 };
	sum[1] = a / 100, sum[2] = (a / 10) % 10, sum[3] = a % 10;
	sum[4] = b / 100, sum[5] = (b / 10) % 10, sum[6] = b % 10;
	sum[7] = c / 100, sum[8] = (c / 10) % 10, sum[9] = c % 10;
	for (int i = 1; i <= 9; ++i)
		for (int j = 1; j < i; ++j) 
			if (sum[i] == sum[j] || sum[j] == 0)return 0;
	return 1;
}