#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define ll  long long
#define INF 1e18
using namespace std;

const int N = 1e6 + 7;
int n;
ll a[N];

int main() {
	cin >> n;
	ll ma = 0, mi = INF;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		ma = max(ma, a[i]), mi = min(mi, a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		cout << ma - a[i];
		if (i < n)cout << " ";
		else cout << endl;
	}
	for (int i = 1; i <= n; ++i) {
		cout << a[i] - mi;
		if (i < n)cout << " ";
		else cout << endl;
	}
	return 0;
}