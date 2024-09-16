#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int n, k;
int pr[11];
bool f[11];

inline void Print() {
	for (int i = 1; i < k; ++i)
		cout << pr[i] << " ";
	cout << pr[k] << endl;
	return;
}

inline void DFS(int i, int count) {
	if (i > n) {
		if (count == k)Print();
		return;
	}
	if (count == k) {
		Print();
		return;
	}
	if (!f[i]) {
		f[i] = true;
		pr[++count] = i;
		DFS(i, count);
		f[i] = false;
		pr[count--] = 0;
	}
	else {
		for (int j = 1; j <= n; ++j)
			if (!f[j])DFS(j, count);
	}
	return;
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		DFS(i, 0);
	return 0;
}