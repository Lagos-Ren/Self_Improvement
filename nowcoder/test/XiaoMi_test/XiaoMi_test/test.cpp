#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define ll long long
#define INF 1e9
using namespace std;

const int N = 30005;
int n;
ll a[N];

int main() {
	cin >> n;
	int ct = 0, pl;
	ll minm = INF;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] < 0)ct++;
		if (minm > abs(a[i]))minm = min(minm, abs(a[i])), pl = i;
	}
	ll ans = 0;
	if (!(ct % 2)) {
		for (int i = 1; i <= n; ++i)
			ans += abs(a[i]);
	}
	else {
		for (int i = 1; i <= n; ++i) {
			if (i == pl)ans -= abs(a[i]);
			else ans += abs(a[i]);
		}
	}
	cout << ans << endl;
	return 0;
}

/*
const int N = 205;
int n, a[N];

inline int Get_Max() {
	int len = 0;
	for (int l = 1; l <= n; ++l) {
		if (a[l])continue;
		int temp = 0;
		for (int r = l; r <= n; ++r) {
			if (!a[r])temp++;
			else {
				l = r - 1;
				break;
			}
		}
		len = max(len, temp);
	}
	return len;
}

inline void Find_Max(int &len) {
	len = Get_Max();
	for (int i = 1; i <= n; ++i) {
		if (a[i]) {
			a[i] = 0;
			len = max(len, Get_Max());
			a[i] = 1;
		}
	}
	return;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		int len;
		Find_Max(len);
		cout << len << endl;
	}
	return 0;
}
*/