#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

char str[114];

int main() {
	cin >> str;
	int len = strlen(str);
	bool flag = false;
	for (int i = 0; i < len / 2; ++i) {
		if (str[i] != str[len - 1 - i]) {
			flag = true;
			break;
		}
	}
	!flag ? cout << "yes" << endl : cout << "no" << endl;
	return 0;
}