#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

inline int Count_2(int n) {
	int tot = 0;
	for (int i = n; i; i /= 10)
		if (i % 10 == 2)tot++;
	return tot;
}

int main() {
	int l, r, ans = 0;
	cin >> l >> r;
	for (int i = l; i <= r; ++i)
		ans += Count_2(i);
	cout << ans << endl;
	return 0;
}