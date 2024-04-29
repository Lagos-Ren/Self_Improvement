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

inline void Visit(int p) {
	cout << p << " ";
	return;
}

inline void PreOrder(int p) {
	if (!p)return;
	Visit(p);
	PreOrder(t[p].lchild);
	PreOrder(t[p].rchild);
	return;
}

inline void InOrder(int p) {
	if (!p)return;
	InOrder(t[p].lchild);
	Visit(p);
	InOrder(t[p].rchild);
	return;
}

inline void PostOrder(int p) {
	if (!p)return;
	PostOrder(t[p].lchild);
	PostOrder(t[p].rchild);
	Visit(p);
	return;
}

int main() {
	cin >> n;
	int l, r;
	for (int i = 1; i <= n; ++i) {
		cin >> l >> r;
		t[i].lchild = l, t[i].rchild = r;
	}
	PreOrder(1);
	cout << endl;
	InOrder(1);
	cout << endl;
	PostOrder(1);
	cout << endl;
	return 0;
}