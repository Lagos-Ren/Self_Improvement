#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#define PI 3.14
using namespace std;

int drink(double V) {
	double n = 20.0;
	if (V >= n)return 1;
	else {
		int c = (int)(n / V);
		double Vc = (double)c * V;
		if (Vc == n)return c;
		else return c + 1;
	}
}

int main() {
	int h, r;
	scanf("%d %d", &h, &r);
	double H = (double)h / 10.0, R = (double)r / 10.0;
	double V = PI * R * R * H;
	printf("%d\n", drink(V));
	return 0;
}