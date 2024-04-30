#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int MAXN = 1e6 + 7;
struct TreeNode {
	int lchild = 0, rchild = 0;
}t[MAXN];
int n;

inline int Dep(int p) {
	if (!p)return 0;
	else {
		int ld = Dep(t[p].lchild);
		int rd = Dep(t[p].rchild);
		return ld > rd ? ld + 1 : rd + 1;
	}
}

int main() {
	cin >> n;
	int l, r;
	for (int i = 1; i <= n; ++i) {
		cin >> l >> r;
		t[i].lchild = l, t[i].rchild = r;
	}
	int depth = Dep(1);
	cout << depth << endl;
	return 0;
}