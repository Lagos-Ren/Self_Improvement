#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	char ch = getchar();
	int n = (int)ch;
	if (!(n % 2))cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}