#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int N = 3e5 + 5;
int n, k;
ll a[N], S[N];

inline ll Get_gcd(ll x, ll y) {
	if (x < y)swap(x, y);
	return !(x % y) ? y : Get_gcd(y, x % y);
}

int main() {
	memset(S, 0, sizeof(S));
	cin >> n >> k;
	if (n == 1) {
		cin >> a[1];
		cout << "-1" << endl;
		return 0;
	}
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 2; i <= n; ++i)
		S[i] = S[i - 1] + Get_gcd(a[i - 1], a[i]);
	if (k == 1)cout << "-1" << endl;
	else {
		if (n < k)cout << S[n - 1] << endl;
		else cout << S[k] << endl;
	}
	return 0;
}

/*
		ll s = 0;
		int m = min(n, k);
		for (int i = 1; i <= m; ++i) {
			for (int l = i; l <= m; ++l) {
				for (int r = l + 1; r <= m; ++r) {
					ll temp = 0;
					for (int j = l; j <= r - 1; ++j) {
						temp += Get_gcd(a[j], a[j + 1]);
					}
					s = max(s, temp);
				}
			}
		}
		cout << s << endl;
*/

/*
//1
#define ull unsigned long long
int main() {
	ull c;
	cin >> c;
	ull a, b;
	if (!(c % 2))a = b = c / 2;
	else a = c / 2, b = a + 1;
	cout << a * b << endl;
	return 0;
}
*/