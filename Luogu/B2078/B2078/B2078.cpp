#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	char str[15];
	int len, k, n = 0;
	cin >> str >> k;
	len = strlen(str);
	for (int i = 0; i < len; ++i)
		if (str[i] == '3')n++;
	n == k ? cout << "YES" << endl : cout << "NO" << endl;
	return 0;
}