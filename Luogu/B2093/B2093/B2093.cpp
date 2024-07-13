#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 10005;

inline bool Find(int n) {
	int x, a[N];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	cin >> x;
	for (int i = 0; i < n; ++i) {
		if (a[i] == x) {
			cout << i << endl;
			return true;
		}
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	if (!Find(n))cout << "-1" << endl;
	return 0;
}