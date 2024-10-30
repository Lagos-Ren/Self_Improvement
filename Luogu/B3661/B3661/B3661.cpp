#define _CRT_SECURE_NO_WARNINGS 1 
#include<cmath>
#include<cstdio>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n, a;
	cin >> n;
	vector<int>O, B;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		!(a % 2) ? B.push_back(a) : O.push_back(a);
	}
	for (int i = 0; i < O.size(); ++i)
		cout << O[i] << " ";
	cout << endl;
	for (int i = 0; i < B.size(); ++i)
		cout << B[i] << " ";
	cout << endl;
	return 0;
}