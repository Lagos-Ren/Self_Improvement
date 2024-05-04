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

ThreadNode* pre = NULL;//全局变量pre，指向当前访问节点的前驱

void visit(ThreadNode* q) {
	if (q->lchild == NULL) {//左子树为空，建立前驱线索
		q->lchild = pre;
		q->ltag = true;
	}
	if (pre != NULL && pre->rchild == NULL) {
		pre->rchild = q;//建立前驱节点的后继线索
		pre->rtag = true;
	}
	pre = q;
	return;
}

void InThread(ThreadTree T) {//中序遍历二叉树，并线索化
	if (T != NULL) {
		InThread(T->lchild);
		visit(T);
		InThread(T->rchild);
	}
	return;
}

void CreateInThread(ThreadTree T) {//中序线索化二叉树T
	pre = NULL;//pre初始为NULL
	if (T != NULL) {//若二叉树非空
		InThread(T);//中序遍历并线索化处理
		if (pre->rchild == NULL)
			pre->rtag = true;//对最后一个结点特殊处理
	}
	return;
}

void PreThread(ThreadTree T) {//先序遍历二叉树并线索化
	if (T != NULL) {
		visit(T);//先处理根节点
		if (!T->ltag)PreThread(T->lchild);//若左孩子不是线索才处理
		PreThread(T->rchild);
	}
	return;
}

void CreatePreThread(ThreadTree T) {//创建先序线索二叉树
	pre = NULL;
	if (T != NULL) {
		PreThread(T);
		if (pre->rchild == NULL)
			pre->rtag = true;//对最后一个结点特殊处理
	}
	return;
}

void PostThread(ThreadTree T) {//后序遍历二叉树并线索化
	if (T != NULL) {
		PostThread(T->lchild);
		PostThread(T->rchild);
		visit(T);//最后处理根结点
		//因此无需担心左右子树被线索化后可能产生“死循环”
	}
	return;
}

void CreatePostThread(ThreadTree T) {//创建后序线索二叉树
	pre = NULL;
	if (T != NULL) {
		PostThread(T);
		if (pre->rchild == NULL)
			pre->rtag = true;
	}
	return;
}



int main() {

	return 0;
}