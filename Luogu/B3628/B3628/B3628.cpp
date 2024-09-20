#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;

const int N = 100007;
int n, a[N];

int main() {
	memset(a, 0, sizeof(a));
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	ll res = 0, ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] < 0)res += a[i];
		if (a[i] > 0) {
			ans = min(res, ans);
			res += a[i];
		}
	}
	ans = min(res, ans);
	cout << ans * (-1) + 1 << endl;
	return 0;
}