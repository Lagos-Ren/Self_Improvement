#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 1145;

int main() {
	int n, m, a[N];
	long long ans = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		cin >> m;
		ans += m * a[i];
	}
	cout << ans << endl;
	return 0;
}