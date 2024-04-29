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

void visit(BiTree T) {
	printf("%d ", T->data.value);
	return;
}
void PreOrder(BiTree T) {//��������������ң�
	if (T != NULL) {
		visit(T);//���ʸ����
		PreOrder(T->lchild);//�ݹ����������
		PreOrder(T->rchild);//�ݹ����������
	}
	return;
}

void InOrder(BiTree T) {//�������������ң�
	if (T != NULL) {
		InOrder(T->lchild);//�ݹ����������
		visit(T);//���ʸ����
		InOrder(T->rchild);//�ݹ����������
	}
	return;
}

void PostOrder(BiTree T) {//������������Ҹ���
	if (T != NULL) {
		InOrder(T->lchild);//�ݹ����������
		InOrder(T->rchild);//�ݹ����������
		visit(T);//���ʸ����
	}
	return;
}

int TreeDepty(BiTree T) {//���������
	if (T == NULL)return 0;//�������Ϊ�շ���0
	else {
		int l = TreeDepty(T->lchild);//�ݹ������������
		int r = TreeDepty(T->rchild);//�ݹ������������
		return l > r ? l + 1 : r + 1;//�������=max(���������,���������)+1
	}
}

typedef struct LNode {//������洢ջ
	struct BiTNode* Node;//��Ŷ��������
	struct LNode* next;
}LNode,*LinkList;

void InitLink(LinkList & S) {//��ʼ��ջ
	S = (LinkList)malloc(sizeof(LNode));
	if (S == NULL)return;
	S->next = NULL;
	return;
}

bool Is_Empty(LinkList S) {//��ջ��
	return S->next == NULL ? true : false;
}

void Push(LinkList& S, BiTree p) {//��ջ
	LNode* q = (LNode*)malloc(sizeof(LNode));
	q->Node = p;
	q->next = S->next;
	S->next = q;
	return;
}

void Pop(LinkList& S, BiTree& p) {//��ջ
	if (Is_Empty(S))return;
	LNode* q = S->next;
	p = q->Node;
	S->next = q->next;
	free(q);
	return;
}

void InOrder2(BiTree T) {//��������������ķǵݹ��㷨
	LinkList S;//����ջ
	InitLink(S);//��ʼ��ջ
	BiTree p = T;//����ָ��p
	while (p || !Is_Empty(S)) {//ջ���ջ�p����ʱѭ��
		if (p) {//һ·����
//			visit(p);//��Ϊǰ����������ڴ˷����ȵ�ǰ��㣬����ջ
			Push(S, p);//��ǰ�����ջ
			p = p->lchild;//���Ӳ�����һֱ������
		}
		else {//��ջ����ת���ջ�����Һ���
			Pop(S, p);//ջ��Ԫ�س�ջ
			visit(p);//���ʳ�ջ���
			p = p->rchild;//������������p��ֵΪ��ǰ�����Һ���
		}//����ѭ��
	}
	return;
}

int main() {

	return 0;
}