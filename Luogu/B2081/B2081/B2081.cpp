#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

inline bool Relate_7(int n) {
	if (!(n % 7))return true;
	else {
		for (int i = n; i; i /= 10)
			if (i % 10 == 7)return true;
	}
	return false;
}

inline int Squ(int n) {
	return n * n;
}

int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		if (!Relate_7(i))ans += Squ(i);
	cout << ans << endl;
	return 0;
}