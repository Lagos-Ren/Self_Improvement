#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

inline double Height(double h) {
	return h / 2.0;
}

int main() {
	int n; cin >> n;
	double h = double(n), tot = 0.0;
	for (int i = 1; i <= 10; ++i) {
		if (i == 1)tot += h;
		else tot += h * 2.0;
		h = Height(h);
	}
	cout << tot << endl << h << endl;
	return 0;
}