#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

inline void Work(int a, int b, char ch, int f) {
	char blank;
	if (!f)blank = ' ';
	else blank = ch;
	for (int i = 1; i <= a; ++i) {
		for (int j = 1; j <= b; ++j) {
			i == 1 || j == 1 || i == a || j == b ? cout << ch : cout << blank;
		}
		cout << endl;
	}

	return;
}

int main() {
	int a, b, f;
	char c;
	cin >> a >> b >> c >> f;
	Work(a, b, c, f);
	return 0;
}