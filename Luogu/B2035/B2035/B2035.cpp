#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
using namespace std;

int main() {
	long long n;
	scanf("%lld", &n);
	if (!n)printf("zero\n");
	else {
		if (n < 0)printf("negative\n");
		else printf("positive\n");
	}
	return 0;
}