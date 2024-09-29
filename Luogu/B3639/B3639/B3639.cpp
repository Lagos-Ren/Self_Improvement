#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 1005;
int n, m;
bool La[N];

inline void Oper(int a) {
	int b = a - 1, c = a + 1;
	if (a == 1)b = n;
	else if (a == n)c = 1;
	La[a] = !La[a], La[b] = !La[b], La[c] = !La[c];
	return;
}

int main() {
	memset(La, false, sizeof(La));
	cin >> n >> m;
	for (int i = 1, a; i <= m; ++i) {
		cin >> a;
		Oper(a);
	}
	for (int i = 1; i <= n; ++i) {
		if (i < n)cout << La[i] << " ";
		else cout << La[i] << endl;
	}
	return 0;
}