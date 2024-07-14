#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 114;
int n, indegree[N], print[N];
bool A[N][N];

inline void Init() {
	cin >> n;
	for (int i = 0; i <= n; ++i) {
		indegree[i] = 0;
		for (int j = 0; j <= n; ++j) {
			A[i][j] = false;
		}
	}
	for (int i = 1, j; i <= n; ++i) {
		for (int k = 0; k <= n; ++k) {
			cin >> j;
			if (!j)break;
			A[i][j] = true;
			indegree[j]++;
		}
	}
	return;
}

inline bool TopologicalSort() {
	int Sta[N], top = 0, count = 0;
	memset(Sta, 0, sizeof(Sta));
	int i;
	for (i = 1; i <= n; ++i)
		if (!indegree[i])Sta[++top] = i;
	while (top) {
		i = Sta[top--];
		print[++count] = i;
		for (int j = 1; j <= n; ++j)
			if (A[i][j]) {
				A[i][j] = false, indegree[j]--;
				if (!indegree[j])Sta[++top] = j;
			}
	}
	if (count < n)return false;
	else return true;
}

int main() {
	Init();
	if (!TopologicalSort())cout << "Error!" << endl;
	else {
		for (int i = 1; i <= n; ++i)
			cout << print[i] << " ";
		cout << endl;
	}
	return 0;
}