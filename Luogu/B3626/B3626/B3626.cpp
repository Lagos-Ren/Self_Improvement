//Î´Íê³É
#define _CRT_SECURE_NO_WARNINGS 1
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1000007;
int n, step = 0;
queue<int>q;
bool f[N];

inline void BFS(int x) {
	q.push(x);
	bool flag = false;
	while (!q.empty()) {
		if (flag)break;
		step++;
		for (int i = q.front();; q.pop()) {
			if (i == n) {
				flag = true;
				break;
			}
			if (i - 1 >= 1)
				if (!f[i - 1])
					q.push(i - 1), f[i - 1] = true;
			if (i + 1 <= n)
				if (!f[i + 1])
					q.push(i + 1), f[i + 1] = true;
			if (i * 2 <= n)
				if (!f[i * 2])
					q.push(i * 2), f[i * 2] = true;
		}
	}
	return;
}

int main() {
	cin >> n;
	BFS(1);
	cout << step << endl;
	return 0;
}