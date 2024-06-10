#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

double Func(double x) {
	if (0.0 <= x && x < 5.0)return (-1) * x + 2.5;
	else if (5.0 <= x && x < 10.0)return 2.0 - 1.5 * (x - 3.0) * (x - 3.0);
	else if (10.0 <= x && x < 20.0)return x / 2.0 - 1.5;
}

int main() {
	double x;
	scanf("%lf", &x);
	printf("%.3lf\n", Func(x));
	return 0;
}