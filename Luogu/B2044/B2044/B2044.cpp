#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	for (int i = 0; i < 3; ++i) 
		for (int j = 0; j < 3; ++j) 
			if (a[i] < a[j])swap(a[i], a[j]);
	if (a[0] < 60 && a[1] >= 60)cout << "1" << endl;
	else cout << "0" << endl;
	return 0;
}