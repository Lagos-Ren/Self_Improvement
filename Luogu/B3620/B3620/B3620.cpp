#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

int x;
char S[40];

inline int Get_Num(char ch) {
	if (ch >= '0' && ch <= '9')return ch - '0';
	else return ch - 'A' + 10;
}

int main() {
	cin >> x >> S;
	int len = strlen(S);
	reverse(S, S + len);
	ll num = 0;
	for (int i = 0; i < len; ++i)
		num += Get_Num(S[i]) * pow(x, i);
	cout << num << endl;
	return 0;
}