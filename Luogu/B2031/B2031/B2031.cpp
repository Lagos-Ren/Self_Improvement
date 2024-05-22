#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;

double x_1, x_2, x_3, y_1, y_2, y_3;
double D, H, S;

bool Judge() {
	if (x_1 == x_2) {
		D = abs(y_1 - y_2);
		H = abs(x_3 - x_1);
		S = D * H / 2.0;
		printf("%.2lf\n", S);
		return true;
	}
	else if (x_1 == x_3) {
		D = abs(y_1 - y_3);
		H = abs(x_2 - x_1);
		S = D * H / 2.0;
		printf("%.2lf\n", S);
		return true;
	}
	else if (x_2 == x_3) {
		D = abs(y_2 - y_3);
		H = abs(x_3 - x_1);
		S = D * H / 2.0;
		printf("%.2lf\n", S);
		return true;
	}
	else if (y_1 == y_2) {
		D = abs(x_1 - x_2);
		H = abs(y_3 - y_1);
		S = D * H / 2.0;
		printf("%.2lf\n", S);
		return true;
	}
	else if (y_1 == y_3) {
		D = abs(x_1 - x_3);
		H = abs(y_2 - y_1);
		S = D * H / 2.0;
		printf("%.2lf\n", S);
		return true;
	}
	else if (y_2 == y_3) {
		D = abs(x_3 - x_2);
		H = abs(y_3 - y_1);
		S = D * H / 2.0;
		printf("%.2lf\n", S);
		return true;
	}
	else return false;
}

int main() {
	scanf("%lf %lf %lf %lf %lf %lf", &x_1, &y_1, &x_2, & y_2, &x_3, &y_3);
	if (Judge())return 0;
	double a, b, k, d, x_4, y_4;
	a = (y_1 - y_2) / (x_1 - x_2);
	b = y_1 - a * x_1;
	k = a * (-1);
	d = y_3 - k * x_3;
	x_4 = (b - d) / (k - a);
	y_4 = (k * x_4 + d + a * x_4 + b) / 2;
	D = sqrt((x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2));
	H= sqrt((x_3 - x_4) * (x_3 - x_4) + (y_3 - y_4) * (y_3 - y_4));
	S = D * H / 2;
	printf("%.2lf\n", S);
	return 0;
}