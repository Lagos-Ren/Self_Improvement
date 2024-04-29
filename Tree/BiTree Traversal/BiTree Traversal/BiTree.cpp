#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

typedef struct ElemType {
	int value;
}ElemType;
typedef struct BiTNode {
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
BiTree root;//声明一棵二叉树

void visit(BiTree T) {
	printf("%d ", T->data.value);
	return;
}
void PreOrder(BiTree T) {//先序遍历（根左右）
	if (T != NULL) {
		visit(T);//访问根结点
		PreOrder(T->lchild);//递归访问左子树
		PreOrder(T->rchild);//递归访问右子树
	}
	return;
}

void InOrder(BiTree T) {//中序遍历（左根右）
	if (T != NULL) {
		InOrder(T->lchild);//递归访问左子树
		visit(T);//访问根结点
		InOrder(T->rchild);//递归访问右子树
	}
	return;
}

void PostOrder(BiTree T) {//后序遍历（左右根）
	if (T != NULL) {
		InOrder(T->lchild);//递归访问左子树
		InOrder(T->rchild);//递归访问右子树
		visit(T);//访问根结点
	}
	return;
}

int TreeDepty(BiTree T) {//求树的深度
	if (T == NULL)return 0;//若根结点为空返回0
	else {
		int l = TreeDepty(T->lchild);//递归求左子树深度
		int r = TreeDepty(T->rchild);//递归求右子树深度
		return l > r ? l + 1 : r + 1;//树的深度=max(左子树深度,右子树深度)+1
	}
}

typedef struct LNode {//单链表存储栈
	struct BiTNode* Node;//存放二叉树结点
	struct LNode* next;
}LNode,*LinkList;

void InitLink(LinkList & S) {//初始化栈
	S = (LinkList)malloc(sizeof(LNode));
	if (S == NULL)return;
	S->next = NULL;
	return;
}

bool Is_Empty(LinkList S) {//判栈空
	return S->next == NULL ? true : false;
}

void Push(LinkList& S, BiTree p) {//入栈
	LNode* q = (LNode*)malloc(sizeof(LNode));
	q->Node = p;
	q->next = S->next;
	S->next = q;
	return;
}

void Pop(LinkList& S, BiTree& p) {//出栈
	if (Is_Empty(S))return;
	LNode* q = S->next;
	p = q->Node;
	S->next = q->next;
	free(q);
	return;
}

void InOrder2(BiTree T) {//中序遍历二叉树的非递归算法
	LinkList S;//声明栈
	InitLink(S);//初始化栈
	BiTree p = T;//遍历指针p
	while (p || !Is_Empty(S)) {//栈不空或p不空时循环
		if (p) {//一路向左
//			visit(p);//若为前序遍历，则在此访问先当前结点，并入栈
			Push(S, p);//当前结点入栈
			p = p->lchild;//左孩子不空则一直向左走
		}
		else {//出栈，并转向出栈结点的右孩子
			Pop(S, p);//栈顶元素出栈
			visit(p);//访问出栈结点
			p = p->rchild;//走向右子树，p赋值为当前结点的右孩子
		}//返回循环
	}
	return;
}

int main() {

	return 0;
}