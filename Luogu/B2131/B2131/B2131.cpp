#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define Fever 37.5
using namespace std;

int main() {
	int n, tot = 0;
	char str[12];
	float tem;
	bool cou;
	cin >> n;
	while (n--) {
		cin >> str >> tem >> cou;
		if (tem >= 37.5 && cou) { cout << str << endl; tot++; }
	}
	cout << tot << endl;
	return 0;
}