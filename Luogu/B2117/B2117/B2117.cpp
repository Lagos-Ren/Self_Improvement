#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 114;
char str[N];

inline char Conver(char ch) {
	if (ch >= 'a' && ch <= 'z')return ch - 32;
	else if (ch >= 'A' && ch <= 'Z')return ch + 32;
	else return ch;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		cin >> str;
		int len = strlen(str);
		if (str[0] >= '0' && str[0] <= '9') {
			for (int i = 0; i < len; ++i) {
				str[i] = (str[i] >= 'A' && str[i] <= 'Z') ? Conver(str[i]) : str[i];
			}
		}
		else {
			str[0] = (str[0] >= 'a' && str[0] <= 'z') ? str[0] - 32 : str[0];
			for (int i = 1; i < len; ++i) {
				str[i] = (str[i] >= 'A' && str[i] <= 'Z') ? Conver(str[i]) : str[i];
			}
		}
		cout << str << endl;
	}
	return 0;
}