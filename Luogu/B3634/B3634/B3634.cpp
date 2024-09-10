#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;

inline int Get_gcd(int a, int b) {
	//int g;
	//for (int i = b; i >= 1; --i)
	//	if (!(a % i) && !(b % i)) {
	//		g = i; break;
	//	}
	//return g;
	return !(a % b) ? b : Get_gcd(b, a % b);
}

inline ll Lcm(int a, int b, int g) {
	return (ll)a * (ll)b / (ll)g;
}

int main() {
	int a, b;
	cin >> a >> b;
	if (a < b)swap(a, b);
	int g = Get_gcd(a, b);
	cout << g << " " << Lcm(a, b, g) << endl;
	return 0;
}