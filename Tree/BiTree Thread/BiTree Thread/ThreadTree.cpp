#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

typedef struct ElemType {
	int value;
}ElemType;

typedef struct BiTNode {//�������Ľ�㣨��ʽ�洢��
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

typedef struct ThreadNode {//�������������
	ElemType data;
	struct ThreadNode* lchild, * rchild;
	bool ltag = false, rtag = false;//����������־
	//��tagֵΪ0��ʱ�򣬱�ʾָ��ָ����
	//��tagֵΪ1��ʱ�򣬱�ʾָ��ָ������
}ThreadNode, * ThreadTree;

ThreadNode* pre = NULL;//ȫ�ֱ���pre��ָ��ǰ���ʽڵ��ǰ��

void visit(ThreadNode* q) {
	if (q->lchild == NULL) {//������Ϊ�գ�����ǰ������
		q->lchild = pre;
		q->ltag = true;
	}
	if (pre != NULL && pre->rchild == NULL) {
		pre->rchild = q;//����ǰ���ڵ�ĺ������
		pre->rtag = true;
	}
	pre = q;
	return;
}

void InThread(ThreadTree T) {//�����������������������
	if (T != NULL) {
		InThread(T->lchild);
		visit(T);
		InThread(T->rchild);
	}
	return;
}

void CreateInThread(ThreadTree T) {//����������������T
	pre = NULL;//pre��ʼΪNULL
	if (T != NULL) {//���������ǿ�
		InThread(T);//�������������������
		if (pre->rchild == NULL)
			pre->rtag = true;//�����һ��������⴦��
	}
	return;
}

void PreThread(ThreadTree T) {//���������������������
	if (T != NULL) {
		visit(T);//�ȴ�����ڵ�
		if (!T->ltag)PreThread(T->lchild);//�����Ӳ��������Ŵ���
		PreThread(T->rchild);
	}
	return;
}

void CreatePreThread(ThreadTree T) {//������������������
	pre = NULL;
	if (T != NULL) {
		PreThread(T);
		if (pre->rchild == NULL)
			pre->rtag = true;//�����һ��������⴦��
	}
	return;
}

void PostThread(ThreadTree T) {//���������������������
	if (T != NULL) {
		PostThread(T->lchild);
		PostThread(T->rchild);
		visit(T);//���������
		//������赣����������������������ܲ�������ѭ����
	}
	return;
}

void CreatePostThread(ThreadTree T) {//������������������
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