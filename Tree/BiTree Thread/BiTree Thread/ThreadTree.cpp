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

//�ҵ���pΪ���������е�һ��������������Ľ��
ThreadNode* FirstNode(ThreadNode* p) {
	while (!p->ltag)p = p->lchild;//ѭ���ҵ������½ǵĽ�㣨��һ����Ҷ��㣩
	return p;
}
//�������������������ҵ����p�ĺ�̽��
ThreadNode* NextNode(ThreadNode* p) {
	if (p->rtag == 0)return FirstNode(p->rchild);
	//����������Ϊ�գ��򷵻��������е�һ��������������Ľ��
	else return p->rchild;//����ֱ�ӷ����Һ��ӣ����������
}

void _Visit(ThreadNode* p) {
	cout << p->data.value << " ";
	return;
}
//��������ʵ�ֶ���������������������������ǵݹ��㷨��
void InOrder(ThreadNode* T) {
	for (ThreadNode* p = FirstNode(T); p != NULL; p = NextNode(p))
		_Visit(p);
	return;
}

//�ҵ���pΪ�������������һ��������������Ľ��
ThreadNode* LastNode(ThreadNode* p) {
	while (!p->rtag)p = p->rchild;//ѭ���ҵ������½ǵĽ�㣨��һ����Ҷ��㣩
	return p;
}
//�������������������ҵ����p��ǰ�����
ThreadNode* PreNode(ThreadNode* p) {
	if (p->ltag == 0)return LastNode(p->lchild);
	//����������Ϊ�գ��򷵻������������һ��������������Ľ��
	else return p->lchild;//����ֱ�ӷ������ӣ�ǰ��������
}
//��������ʵ�ֶ�������������������������������ǵݹ��㷨��
void RevInOrder(ThreadNode* T) {
	for (ThreadNode* p = LastNode(T); p != NULL; p = PreNode(p))
		_Visit(p);
	return;
}

int main() {

	return 0;
}