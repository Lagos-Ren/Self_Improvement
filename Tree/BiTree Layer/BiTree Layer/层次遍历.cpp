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
BiTree root;//����һ�ö�����

void Visit(BiTree p) {
	cout << p->data.value << " ";
	return;
}

typedef struct LinkNode {//������
	BiTree Node;//�������Ŷ��������
	struct LinkNode* next;
}LinkNode, * LinkList;
typedef struct {//������
	LinkNode* front, * rear;
}LinkQueue;

void InitQueue(LinkQueue& Q) {//���г�ʼ����Ĭ�ϴ�ͷ��㣩
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
	return;
}

bool Is_Empty(LinkQueue Q) {//�����п�
	return Q.front == Q.rear ? true : false;
}

void EnQueue(LinkQueue& Q, BiTree T) {//���
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	if (p == NULL)return;
	p->Node = T;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return;
}

void DeQueue(LinkQueue& Q, BiTree& p) {//����
	if (Is_Empty(Q))return;
	LinkNode* h = Q.front->next;
	p = h->Node;
	Q.front->next = h->next;
	if (Q.rear == h)Q.rear = Q.front;
	free(h);
	return;
}

void LevelOrder(BiTree T) {//��������α���
	LinkQueue Q;
	InitQueue(Q);//��ʼ����������
	BiTree p;
	EnQueue(Q, T);//��������
	while (!Is_Empty(Q)) {//�����в�Ϊ��ʱ
		DeQueue(Q, p);//��ͷ������
		Visit(p);//���ʶ�ͷ���
		if (p->lchild != NULL)EnQueue(Q, p->lchild);
		//�����Ӳ�Ϊ�գ����������
		if (p->rchild != NULL)EnQueue(Q, p->rchild);
		//���Һ��Ӳ�Ϊ�գ����Һ������
	}
	return;
}

int main() {

	return 0;
}