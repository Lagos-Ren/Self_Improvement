#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 55;
char str[N];

inline char Chan(char ch) {
	return ch <= 'Z' ? ch + 32 : ch - 32;
}

inline char Mov(char ch) {
	return ch >= 'a' ? (ch >= 'x' ? ch - 23 : ch + 3) : (ch >= 'X' ? ch - 23 : ch + 3);
}

int main() {
	cin >> str;
	int len = strlen(str);
	for (int i = 0; i < len; ++i)str[i] = Chan(str[i]);
	reverse(str, str + len);
	for (int i = 0; i < len; ++i)str[i] = Mov(str[i]);
	cout << str << endl;
	return 0;
}