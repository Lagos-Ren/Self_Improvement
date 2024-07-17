#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

#define INF 0x7fffffff
int num[6][6];
bool flag = false, ma[6][6], mi[6][6];

int main() {
	for (int i = 1; i <= 5; ++i) {
		for (int j = 1; j <= 5; ++j) {
			cin >> num[i][j];
			ma[i][j] = mi[i][j] = false;
		}
	}
	for (int i = 1; i <= 5; ++i) {
		int maxm = -INF, k;
		for (int j = 1; j <= 5; ++j) {
			if (num[i][j] > maxm)maxm = num[i][j], k = j;
		}
		ma[i][k] = true;
	}
	for (int i = 1; i <= 5; ++i) {
		int minm = INF, k;
		for (int j = 1; j <= 5; ++j) {
			if (num[j][i] < minm)minm = num[j][i], k = j;
		}
		mi[k][i] = true;
	}
	for (int i = 1; i <= 5; ++i) {
		for (int j = 1; j <= 5; ++j) {
			if (ma[i][j] && mi[i][j]) {
				cout << i << " " << j << " " << num[i][j] << endl;
				flag = true;
			}
		}
	}
	if (!flag)cout << "not found" << endl;
	return 0;
}