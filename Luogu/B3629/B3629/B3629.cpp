#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;

ll n;

inline ll Ice(ll b, ll g) {
	ll ans = 0;
	while (b) {
		ans += b, g += b;
		b = g / 3;
		g -= b * 3;
	}
	return ans;
}

inline ll Work(ll l, ll r) {
	ll mid = (l + r) / 2;
	ll ans = Ice(mid, 0);
	if (ans == n)return mid;
	else return ans > n ? Work(l, mid - 1) : Work(mid + 1, r);
}

int main() {
	cin >> n;
	ll l = 1, r = n;
//	cout << Work(l, r) << endl;//60pts(TLE)
	cout << (n * 2 + 3) / 3 << endl;
	return 0;
}