#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;

ll n, x;
char B[36], Print[36];

inline void Init() {
	for (int i = 0; i < 10; ++i)
		B[i] = '0' + i;
	for (int i = 10; i < 36; ++i)
		B[i] = 'A' + i - 10;
	cin >> n >> x;
	return;
}

inline void Work() {
	int c = 0;
	while (n) {
		Print[c++] = B[n % x];
		n /= x;
	}
	for (int i = c - 1; i >= 0; --i)
		cout << Print[i];
	cout << endl;
	return;
}

int main() {
	Init();
	Work();
	return 0;
}