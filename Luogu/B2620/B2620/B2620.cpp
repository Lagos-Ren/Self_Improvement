#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	cout << (int)(a > b) << " " << (int)(a <= b) << " " << (int)(a != b) << endl;
	return 0;
}