#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 1e6 + 5;
int f[N];

int main() {
	int n;
	cin >> n;
	f[0] = f[1] = 0;
	for (int i = 2; i <= n; ++i) {
		f[i] = !(i % 2) ? min(f[i - 1] + 1, f[i / 2] + 1) : f[i - 1] + 1;
	}
	cout << f[n] << endl;
	return 0;
}