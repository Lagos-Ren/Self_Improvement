#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

int main() {
	ll n;
	cin >> n;
	cout << (ll)floor(pow((double)n, 1.0 / 3.0)) << endl;
	return 0;
}