#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	char str[114];
	while (scanf("%s", str) != EOF) {
		int len = strlen(str);
		reverse(str, str + len);
		printf("%s\n", str);
	}
	return 0;
}