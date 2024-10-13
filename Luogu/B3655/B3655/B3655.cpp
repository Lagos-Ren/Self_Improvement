#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;

const int N = 1e6 + 5;
int n, d[N];
int v[7] = { 0 };

int main() {
	cin >> n;
	for (int i = 1; i < 7; ++i)
		cin >> v[i];
	for (int i = 1; i <= n; ++i)
		cin >> d[i];
	int ct = 0, flag = 0;
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (!d[i])ct = 0, flag = 0;
		else {
			ct++;
			if (ct >= 365)flag = 6;
			else if (ct >= 120)flag = 5;
			else if (ct >= 30)flag = 4;
			else if (ct >= 7)flag = 3;
			else if (ct >= 3)flag = 2;
			else if (ct >= 1)flag = 1;
		}
		ans += v[flag];
	}
	cout << ans << endl;
	return 0;
}