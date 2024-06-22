#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	int n, k;
	int ct_1 = 0, ct_5 = 0, ct_10 = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> k;
		if (k == 1)ct_1++;
		if (k == 5)ct_5++;
		if (k == 10)ct_10++;
	}
	cout << ct_1 << endl << ct_5 << endl << ct_10 << endl;
	return 0;
}