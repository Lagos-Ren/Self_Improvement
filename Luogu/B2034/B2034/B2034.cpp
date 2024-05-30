#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#define ll long long
using namespace std;

inline ll Power_2(int n) {
	return n == 0 ? 1 : Power_2(n - 1) * 2;
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%lld\n", Power_2(n));
	return 0;
}