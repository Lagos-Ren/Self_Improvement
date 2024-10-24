#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 30005;
int n, m, stu[N];

int main() {
	freopen("std.in", "r", stdin);
	while (cin >> n >> m) {
		for (int i = 1; i <= n; ++i)
			cin >> stu[i];
		char op;
		int u, v;
		while (m--) {
			cin >> op >> u >> v;
			if (op == 'Q') {
				int ma = 0;
				if (u > v)swap(u, v);
				for (int i = u; i <= v; ++i)
					ma = max(ma, stu[i]);
				cout << ma << endl;
			}
			else if (op == 'U')stu[u] = v;
		}
	}
	return 0;
}