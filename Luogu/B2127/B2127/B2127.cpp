#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int n;

inline bool is_Perf(int m) {
	int anc = 0;
	for (int i = 1; i < m; ++i)
		if (!(m % i))anc += i;
	return anc == m ? true : false;
}

int main() {
	cin >> n;
	for (int i = 2; i <= n; ++i)
		if (is_Perf(i))cout << i << endl;
	return 0;
}