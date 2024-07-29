#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 10005;
char str[N];

inline char Conv(char ch) {
	if (ch == 'a')return 'z';
	else if (ch == 'A')return 'Z';
	else return ch - 1;
}

inline bool is_EN(char ch) {
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ? true : false;
}

int main() {
//	freopen("std.in", "r", stdin);
	char ch;
	int len = 0;
	while (scanf("%c", &ch) != EOF) {
		if (is_EN(ch))str[len++] = Conv(ch);
		else str[len++] = ch;
	}
	printf("%s\n", str);
	return 0;
}