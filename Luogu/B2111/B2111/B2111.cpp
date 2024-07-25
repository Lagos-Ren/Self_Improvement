#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 514;
double Std, rt;
char DNA_1[N], DNA_2[N];

int main() {
	cin >> Std;
	scanf("%s", DNA_1);
	scanf("%s", DNA_2);
	int len = strlen(DNA_1), tot = 0;
	for (int i = 0; i < len; ++i)
		if (DNA_1[i] == DNA_2[i])tot++;
	rt = (double)tot / (double)len;
	rt >= Std ? cout << "yes" << endl : cout << "no" << endl;
	return 0;
}