#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	int n, m, ans = 0;
	cin >> m >> n;
	if (!(m % 2))m++;
	for (int i = m; i <= n; i += 2)
		ans += i;
	cout << ans << endl;
	return 0;
}