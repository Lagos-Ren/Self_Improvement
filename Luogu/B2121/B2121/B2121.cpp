#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 114;
string ma, mi, str;

inline bool is_CH(char ch) {
	return ((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')) ? true : false;
}

int main() {
	freopen("std.in", "r", stdin);
	int count = 1;
	scanf("%s", str);
	int len1, len2, len3;
	len1 = len2 = len3 = str.length();
	ma = str, mi = str;
	while (scanf("%s", str) != EOF) {
		len3 = str.length();
		for (int i = 0; i < len3; ++i)
			if (!is_CH(str[i]))str[i] = '\0', len3--;
		if (len1 < len3) {
			len1 = len3;
			ma = str;
		}
		if (len2 > len3) {
			len2 = len3;
			mi = str;
		}
	}
	cout << ma << endl << mi << endl;
	return 0;
}