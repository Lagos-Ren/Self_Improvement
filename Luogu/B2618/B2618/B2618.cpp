#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define PI 3.141593
using namespace std;

inline double V_Cul(double r) {
	return (4.0 / 3.0) * PI * pow(r, 3.0);
}

int main() {
	double r_1 = 4.0, r_2 = 10.0;
	double V = V_Cul(r_1) + V_Cul(r_2);
	cout << (int)pow(V, 1.0 / 3.0) << endl;
	return 0;
}