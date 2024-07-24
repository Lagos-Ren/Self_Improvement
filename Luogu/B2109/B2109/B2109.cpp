#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

inline bool is_Num(char ch) {
	return ch >= '0' && ch <= '9' ? true : false;
}

int main() {
	int tot = 0;
	char ch;
	while (ch = getchar()) {
		if (ch == '\n')break;
		if (is_Num(ch))tot++;
	}
	cout << tot << endl;
	return 0;
}