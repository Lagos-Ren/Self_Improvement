#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a, b, len, maxlen;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		if (i == 1) {
			b = a, len = 1, maxlen = 1;
			continue;
		}
		if (b == a) {
			len++;
			maxlen = max(maxlen, len);
			continue;
		}
		else {
			b = a, len = 1;
			continue;
		}
	}
	cout << maxlen << endl;
	return 0;
}