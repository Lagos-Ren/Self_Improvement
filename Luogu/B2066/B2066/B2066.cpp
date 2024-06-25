#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define SPEED 50.0
#define Up 1.0
#define Down 0.5
#define ll long long
using namespace std;

inline double Tim(double x, double y, double m) {
	return sqrt(x * x + y * y) * 2.0 / SPEED + m * (Up + Down);
}

int main() {
	int n;
	double x, y, m, tot = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x >> y >> m;
		tot += Tim(x, y, m);
	}
	ll tt = (ll)ceil(tot);
	cout << tt << endl;
	return 0;
}