#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<iostream>
using namespace std;

bool Judge(int n) {
	bool flag = false;
	if (!(n % 3))cout << "3 ", flag = true;
	if (!(n % 5))cout << "5 ", flag = true;
	if (!(n % 7))cout << "7 ", flag = true;
	return flag;
}

int main() {
	int n;
	cin >> n;
	if (!Judge(n))cout << "n";
	cout<< endl;
	return 0;
}