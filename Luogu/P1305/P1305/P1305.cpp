#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

typedef struct TreeNode {
	char ch;
	struct TreeNode* parent, * lchild, * rchild;
}TreeNode,*BiTree;
int n;
BiTree root;

int root_, lch[200] = { 0 }, rch[200] = { 0 };
int Num(char c) {
//	printf("c=%c\n", c);
	int m = (int)c;
	if (c == '*')return 0;
	else return (int)(c);
}

void find(int m) {
	if (m == 0)return;
	char ch = (char)m;
	cout << ch;
	find(lch[m]);
	find(rch[m]);
	return;
}

int main() {
	cin >> n;
	char c[3];
	for (int i = 1; i <= n; ++i) {
		cin >> c[0] >> c[1] >> c[2];
/*		TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
		p->ch = c[0];
		if (c[1] == '*') {
			p->lchild = NULL;
		}
		else {
			TreeNode* l = (TreeNode*)malloc(sizeof(TreeNode));
			l->ch = c[1];
			l->lchild = NULL, l->rchild = NULL;
			p->lchild = l;
		}
		if (c[2] == '*') {
			p->rchild = NULL;
		}
		else {
			TreeNode* r = (TreeNode*)malloc(sizeof(TreeNode));
			r->ch = c[2];
			p->rchild = r;
			r->lchild = NULL, r->rchild = NULL;
		}
		if (i == 1)root = p;
		*/
		int p = Num(c[0]), l = Num(c[1]), r = Num(c[2]);
		if (i == 1)root_ = p;
		lch[p] = l, rch[p] = r;
	}
	find(root_);
	return 0;
}