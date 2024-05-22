#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
using namespace std;

double Length(int a, int b, int c, int d) {
	return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

int main() {
	int Xa, Ya, Xb, Yb;
	scanf("%d %d %d %d", &Xa, &Ya, &Xb, &Yb);
	printf("%.3lf\n", Length(Xa, Ya, Xb, Yb));
	return 0;
}