#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int n;
bool f[11];

inline char Get_ch(bool flag) {
	return !flag ? 'N' : 'Y';
}

inline void Print() {
	for (int i = 1; i <= n; ++i)
		cout << Get_ch(f[i]);
	cout << endl;
	return;
}

inline void DFS(int i) {
	if (i > n) {
		Print();
		return;
	}
	DFS(i + 1);
	f[i] = true;
	DFS(i + 1);
	f[i] = false;
	return;
}

int main() {
	cin >> n;
	DFS(1);
	return 0;
}