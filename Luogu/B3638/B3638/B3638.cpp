#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define D 1e-7
using namespace std;

struct Node {
	int x, y;
};

inline double Dis(Node a,Node b) {
	return sqrt(pow(double(a.x - b.x), 2.0) + pow(double(a.y - b.y), 2.0));
}

inline double Squ(double a, double b, double c) {
	double s = (a + b + c) / 2.0;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
	Node a, b, c;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	cout << floor(Squ(Dis(a, b), Dis(a, c), Dis(b, c)) + D) << endl;
	return 0;
}