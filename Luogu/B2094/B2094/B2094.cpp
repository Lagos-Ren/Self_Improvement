#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

#define INF 0x7fffffff
const int N = 114;

int main() {
	int n, maxn = -INF, a[N];
	long long ans = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	for (int i = 1; i <= n; ++i)
		ans += a[i] == maxn ? 0 : a[i];
	cout << ans << endl;
	return 0;
}