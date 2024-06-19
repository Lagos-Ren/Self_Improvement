#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	int n, m, ans = 0;
	cin >> m >> n;
	while (m % 17)m++;
	for (int i = m; i <= n; i += 17)
		ans += i;
	cout << ans << endl;
	return 0;
}