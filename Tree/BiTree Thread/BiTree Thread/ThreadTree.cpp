#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

typedef struct ElemType {
	int value;
}ElemType;

typedef struct BiTNode {//二叉树的结点（链式存储）
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

typedef struct ThreadNode {//线索二叉树结点
	ElemType data;
	struct ThreadNode* lchild, * rchild;
	bool ltag = false, rtag = false;//左、右线索标志
	//当tag值为0的时候，表示指针指向孩子
	//而tag值为1的时候，表示指针指向线索
}ThreadNode, * ThreadTree;



int main() {

	return 0;
}