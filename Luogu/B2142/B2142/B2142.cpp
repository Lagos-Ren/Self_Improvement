#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<iostream>
using namespace std;

inline int Add(int n) {
	return n ? n + Add(n - 1) : 0;
}

int main() {
	int n;
	cin >> n;
	cout << Add(n) << endl;
	return 0;
}