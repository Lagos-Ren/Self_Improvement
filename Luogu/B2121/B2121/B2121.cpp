#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define INF 0x7fffffff
using namespace std;

const int N = 114;
char ma[N], mi[N];
char str[114514];

inline bool is_CH(char ch) {
	return ((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')) ? true : false;
}

int main() {
//	freopen("std.in", "r", stdin);
	int n = 0;
	char ch;
	while (ch = getchar()) {
		if (ch == '\n' || ch == '\0' || ch == EOF)break;
		else str[n++] = ch;
	}
	int len = 0, len1 = 0, len2 = INF;
	for (int i = 0; i < n; ++i) {
		if (is_CH(str[i])) {
			len++;
			continue;
		}
		else {
			if (len == 0)continue;
			if (len > len1) {
				for (int j = 0; j < len; ++j)
					ma[j] = str[i - len + j];
				len1 = len;
			}
			if (len < len2) {
				int j;
				for (j = 0; j < len; ++j)
					mi[j] = str[i - len + j];
				while (is_CH(mi[j]))mi[j] = '\0';
				len2 = len;
			}
			len = 0;
		}
	}
	cout << ma << endl;
	cout << mi << endl;
	return 0;
}