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

const int N = 5005;
int n, a[N], f[N];

int main(){
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		f[i] = 1;
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			if (a[j] < a[i])f[i] = max(f[i], f[j] + 1);
		}
	}
	sort(f + 1, f + 1 + n);
	cout << f[n] << endl;
	return 0;
}