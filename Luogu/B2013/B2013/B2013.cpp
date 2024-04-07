#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>

int main() {
	double F,C;
	scanf("%lf",&F);
	if (F < -459.67)return 0;
	else {
		C = 5.0 * (F - 32.0) / 9.0;
		printf("%.5lf\n",C);
	}
	return 0;
}