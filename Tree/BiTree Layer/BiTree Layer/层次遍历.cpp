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

void Visit(BiTree p) {
	cout << p->data.value << " ";
	return;
}

typedef struct LinkNode {//单链表
	BiTree Node;//数据域存放二叉树结点
	struct LinkNode* next;
}LinkNode, * LinkList;
typedef struct {//链队列
	LinkNode* front, * rear;
}LinkQueue;

void InitQueue(LinkQueue& Q) {//队列初始化（默认带头结点）
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
	return;
}

bool Is_Empty(LinkQueue Q) {//队列判空
	return Q.front == Q.rear ? true : false;
}

void EnQueue(LinkQueue& Q, BiTree T) {//入队
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	if (p == NULL)return;
	p->Node = T;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return;
}

void DeQueue(LinkQueue& Q, BiTree& p) {//出队
	if (Is_Empty(Q))return;
	LinkNode* h = Q.front->next;
	p = h->Node;
	Q.front->next = h->next;
	if (Q.rear == h)Q.rear = Q.front;
	free(h);
	return;
}

void LevelOrder(BiTree T) {//二叉树层次遍历
	LinkQueue Q;
	InitQueue(Q);//初始化辅助队列
	BiTree p;
	EnQueue(Q, T);//根结点入队
	while (!Is_Empty(Q)) {//当队列不为空时
		DeQueue(Q, p);//队头结点出队
		Visit(p);//访问队头结点
		if (p->lchild != NULL)EnQueue(Q, p->lchild);
		//若左孩子不为空，则左孩子入队
		if (p->rchild != NULL)EnQueue(Q, p->rchild);
		//若右孩子不为空，则右孩子入队
	}
	return;
}

int main() {

	return 0;
}