#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
#define ld long double
using namespace std;

const ld Delta = 1e-5;

int main() {
	ll n;
	cin >> n;
	cout << (ll)floor(pow((ld)n, (ld)1.0 / 3.0)+Delta) << endl;
	return 0;
}