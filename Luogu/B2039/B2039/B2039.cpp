#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;

char Comp(ll x, ll y) {
	if (x == y)return '=';
	else return x > y ? '>' : '<';
}

int main() {
	ll x, y;
	cin >> x >> y;
	cout << Comp(x, y) << endl;
	return 0;
}