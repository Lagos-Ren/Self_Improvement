#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#define PI 3.14
using namespace std;

double Volume(int r) {
	double re = (double)r;
	return (4.0 / 3.0) * PI * re * re * re;
}

int main() {
	int r;
	scanf("%d", &r);
	printf("%.5lf\n", Volume(r));
	return 0;
}