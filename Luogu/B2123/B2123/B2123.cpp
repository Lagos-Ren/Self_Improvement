#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 1145;
struct Node {
	int num;
	int count;
}P[N];

int main() {
	char str[N];
	cin >> str;
	int len = strlen(str), top = 0, ct = 0;
	char ch = str[0];
	for (int i = 0; i <= len; ++i) {
		if (str[i] != ch) {
			P[top].count = ct;
			P[top++].num = ch - 48;
			ct = 1, ch = str[i];
		}
		else ct++;
	}
	for (int i = 0; i < top; ++i)cout << P[i].count << P[i].num;
	cout << endl;
	return 0;
}