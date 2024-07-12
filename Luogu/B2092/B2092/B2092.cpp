#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 5140;

int main() {
	int n;
	cin >> n;
	bool flag[N];
	memset(flag, true, sizeof(flag));
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; j += i)
			flag[j] = flag[j] ? false : true;
	for (int i = 1; i <= n; ++i)
		if (!flag[i])cout << i << " ";
	cout << endl;
	return 0;
}