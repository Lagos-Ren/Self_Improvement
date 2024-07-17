#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	int n, m, a;
	long long ans = 0;
	cin >> m >> n;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a;
			if (i == 1 || i == m || j == 1 || j == n)ans += a;
		}
	}
	cout << ans << endl;
	return 0;
}