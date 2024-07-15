#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 114;

int main() {
	int n, a, con = 0, print[N];
	bool flag[N];
	memset(print, 0, sizeof(print));
	memset(flag, false, sizeof(flag));
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		if (!flag[a]) {
			flag[a] = true;
			print[++con] = a;
		}
	}
	for (int i = 1; i <= con; ++i)
		cout << print[i] << " ";
	cout << endl;
	return 0;
}