#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 1e6 + 7;
int n, H[N];

inline void Print(int x) {
	if (!H[x]) {
		cout << x << endl;
		return;
	}
	else {
		cout << x << " ";
		Print(H[x]);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> H[i];
	int fir;
	cin >> fir;
	Print(fir);
	return 0;
}