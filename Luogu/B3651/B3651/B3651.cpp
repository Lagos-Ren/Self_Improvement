#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	ll a, ans = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		if (i == k)ans -= a;
		else ans += a;
	}
	cout << ans << endl;
	return 0;
}