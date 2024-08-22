#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define PI 3.141593
using namespace std;

int main() {
	double r = 5.0;
	cout << 2.0 * PI * r << endl << PI * r * r << endl << 4.0 / 3.0 * PI * r * r * r << endl;
	return 0;
}