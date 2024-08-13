#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 1;; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (((1 + i) * i / 2 - j * 3) == n) {
				cout << j << " " << i << endl;
				return 0;
			}
		}
	}
}