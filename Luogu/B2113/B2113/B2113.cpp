#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 114;
char str1[N], str2[N];

int main() {
	cin >> str1;
	int len = strlen(str1);
	str1[len] = str1[0];
	for (int i = 0; i < len; ++i)
		str2[i] = str1[i] + str1[i + 1];
	cout << str2 << endl;
	return 0;
}