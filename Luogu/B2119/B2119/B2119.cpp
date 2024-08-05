#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 40;
char str[N], op[5];

int main() {
	cin >> str;
	int len = strlen(str);
	op[0] = str[len - 3], op[1] = str[len - 2], op[2] = str[len - 1];
	if (op[0] == 'i' && op[1] == 'n' && op[2] == 'g')str[len - 3] = str[len - 2] = str[len - 1] = '\0';
	else if ((op[1] == 'e' && op[2] == 'r') || (op[1] == 'l' && op[2] == 'y'))str[len - 2] = str[len - 1] = '\0';
	cout << str << endl;;
	return 0;
}