#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 50;
int n, l, r, ct = 0;
int w[N];

inline void DFS(int p,int ans) {
	if (p > n) {
		if (l <= ans && ans <= r)ct++;
		return;
	}
	if (ans + w[p] <= r)DFS(p + 1, ans + w[p]);
	DFS(p + 1, ans);
	return;
}

int main() {
	cin >> n >> l >> r;
	for (int i = 1; i <= n; ++i)
		cin >> w[i];
	sort(w + 1, w + 1 + n);
	DFS(1, 0);
	cout << ct << endl;
	return 0;
}