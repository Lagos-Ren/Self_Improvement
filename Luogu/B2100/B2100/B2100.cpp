#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 1; i <= n; ++i)
		cout << "(" << a << "," << i << ") ";
	cout << endl;
	for (int i = 1; i <= n; ++i)
		cout << "(" << i << "," << b << ") ";
	cout << endl;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if ((i - j) == (a - b))
				cout << "(" << i << "," << j << ") ";
	cout << endl;
	for (; a < n && b > 1; ++a, --b);
	for (int i = a, j = b; i >= 1 && j <= n; --i, ++j)
		cout << "(" << i << "," << j << ") ";
	cout << endl;
	return 0;
}