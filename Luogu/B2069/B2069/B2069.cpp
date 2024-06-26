#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 35;
struct Node {
	int q, p;
}S[N];
int n;
double ans=0.0;

inline void Init() {
	scanf("%d", &n);
	S[1].p = 1, S[1].q = 2;
	for (int i = 1; i < N - 1; ++i) {
		S[i + 1].p = S[i].q;
		S[i + 1].q = S[i].q + S[i].p;
	}
	return;
}

int main() {
	Init();
	for (int i = 1; i <= n; ++i)
		ans += double(S[i].q) / double(S[i].p);
	printf("%.4lf\n", ans);
	return 0;
}