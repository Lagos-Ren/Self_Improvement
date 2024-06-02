#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	n = n % 2;
	if (n)cout << "odd" << endl;
	else cout << "even" << endl;
	return 0;
}