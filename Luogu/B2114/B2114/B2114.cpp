#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 300;
char ch, str[N];

int main() {
	int len = 0;
	while (1) {
		ch = getchar();
		if (ch == 'A')str[len++] = 'T';
		else if (ch == 'T')str[len++] = 'A';
		else if (ch == 'C')str[len++] = 'G';
		else if (ch == 'G')str[len++] = 'C';
		else break;
	}
	cout << str << endl;
	return 0;
}