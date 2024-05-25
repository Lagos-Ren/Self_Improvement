#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
using namespace std;

int main() {
	int a, b, n;
	scanf("%d %d %d", &a, &b, &n);
	if (n == 1)printf("%d\n", a);
	else if (n == 2)printf("%d\n", b);
	else if (n >= 3)printf("%d\n", a + (n - 1) * (b - a));
	return 0;
}