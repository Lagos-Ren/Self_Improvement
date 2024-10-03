#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;

inline static int qread() {
	int x = 0, w = 1;
	char ch = 0;
	while (ch < '0' || ch>'9') {
		if (ch == '-')w = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return x * w;
}

inline static void qwrite(ll x) {
	static int sta[35];
	int top = 0;
	do {
		sta[top++] = x % 10, x /= 10;
	} while (x);
	while (top)putchar(sta[--top] + 48);
	putchar('\n');
	return;
}

int main() {
	int n;
	n = qread();
	ll ans = 0;
	for (register int i = 1; i <= n; ++i) {
		ans += i;
		qwrite(ans);
	}
	return 0;
}