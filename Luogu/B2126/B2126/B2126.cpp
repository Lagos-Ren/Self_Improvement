#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n;
char str[1145];

int main() {
	cin >> n >> str;
	int len = strlen(str), tot = 0;
	bool flag = false;
	char ch = str[0];
	for (int i = 0; i <= len; ++i) {
		if (str[i] != ch)ch = str[i], tot = 1;
		else tot++;
		if (tot == n) {
			flag = true;
			break;
		}
	}
	flag ? cout << ch << endl : cout << "No" << endl;
	return 0;
}