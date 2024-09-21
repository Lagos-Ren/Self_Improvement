#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 10005;
char a[N];

inline bool is_Num(char ch) {
	return ch >= '0' && ch <= '9' ? true : false;
}

int main() {
	while (cin.getline(a, 10005)) {
//		cout << a << endl;
		int len = strlen(a), m;
		long long ans = 0;
		for (int i = 0; i < len; ++i) {
			if (a[i] == ' ')continue;
			m = 0;
			if (is_Num(a[i])) {
				for (; i < len; ++i) {
					if (a[i] == ' ')break;
//					cout << "a[" << i << "]=" << a[i] << endl;
					m = m * 10 + (a[i] - '0');
//					cout << "m=" << m << endl;
				}
			}
			ans += m;
		}
		cout << ans << endl;
	}
	return 0;
}
/*
1 2 3
4 5
0 0 0 0 0

*/

/*
//6
int main() {
	int n, a;
	while (cin >> n) {
		long long ans = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a;
			ans += a;
		}
		cout << ans << endl;
	}
	return 0;
}
*/

/*
//5
int main() {
	int t, n, a;
	cin >> t;
	while (t--) {
		cin >> n;
		long long ans = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a;
			ans += a;
		}
		cout << ans << endl;
	}
	return 0;
}
*/

/*
//4
int main() {
	int n, a;
	while (cin >> n) {
		if (!n)break;
		long long ans = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a;
			ans += a;
		}
		cout << ans << endl;
	}
	return 0;
}
*/

/*
//3
#define ll long long
int main() {
	ll a, b;
	while (cin >> a >> b) {
		if (!a && !b)break;
		cout << a + b << endl;
	}
	return 0;
}
*/

/*
//2
int main() {
	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << a + b << endl;
	}
	return 0;
}
*/

/*
//1
int main() {
	int a, b;
	while (cin >> a >> b) {
		cout << a + b << endl;
	}
	return 0;
}
*/