#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 1145;
int flag[N];
char str[N], c = '0';

inline int Ch_to_Num(char ch) {
	return (int)ch;
}

int main() {
	memset(flag, 0, sizeof(flag));
	scanf("%s", str);
	int len = strlen(str);
	for (int i = 0; i < len; ++i)
		flag[Ch_to_Num(str[i])]++;
	for (int i = 0; i < len; ++i)
		if (flag[Ch_to_Num(str[i])] == 1) { c = str[i]; break; }
	if (c=='0')cout << "no" << endl;
	else cout << c << endl;
	return 0;
}