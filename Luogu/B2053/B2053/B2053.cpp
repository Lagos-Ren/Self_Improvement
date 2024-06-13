#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

void Func(double a, double b, double c, double delta, double& x_1, double& x_2) {
	x_1 = (-b + sqrt(delta)) / (2 * a);
	x_2 = (-b - sqrt(delta)) / (2 * a);
	if (x_1 > x_2)swap(x_1, x_2);
	return;
}

int main() {
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);
	double delta, x_1, x_2;
	delta = b * b - 4 * a * c;
	if (delta < 0)printf("No answer!\n");
	else {
		Func(a, b, c, delta, x_1, x_2);
		if (!delta)printf("x1=x2=%.5lf\n", x_1);
		else printf("x1=%.5lf;x2=%.5lf\n", x_1, x_2);
	}
	return 0;
}