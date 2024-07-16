#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	int A[6][6] = { 0 }, print[6] = { 0,1,2,3,4,5 };
	int m, n;
	for (int i = 1; i <= 5; ++i)
		for (int j = 1; j <= 5; ++j)
			cin >> A[i][j];
	cin >> m >> n;
	swap(print[m], print[n]);
	for (int i = 1; i <= 5; ++i) {
		for (int j = 1; j <= 5; ++j) {
			cout << A[print[i]][j] << " ";
		}
		cout << endl;
	}
	return 0;
}