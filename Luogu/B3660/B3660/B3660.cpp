#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	int T, n;
	cin >> T;
	while (T--) {
		int a;
		bool flag = false;
		cin >> n;
		while (n--) {
			cin >> a;
			if (!a)flag = true;
		}
		flag ? cout << "yes" << endl : cout << "no" << endl;
	}
	return 0;
}