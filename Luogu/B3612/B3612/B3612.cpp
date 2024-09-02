#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;

const int N = 1e5 + 7;
int n, m;
int a[N];
ll ans[N] = { 0 };

int main() {
	memset(a, 0, sizeof(a));
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		ans[i] = ans[i - 1] + a[i];
	}
	cin >> m;
	int l, r;
	for (int i = 1; i <= m; ++i) {
		cin >> l >> r;
		cout << ans[r] - ans[l - 1] << endl;
	}
	return 0;
}