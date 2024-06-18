#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a, b, c, na = 0, nb = 0, nc = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a >> b >> c;
		na += a, nb += b, nc += c;
	}
	cout << na << " " << nb << " " << nc << " " << na + nb + nc << endl;
	return 0;
}