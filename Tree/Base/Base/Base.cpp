#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

#define MaxSize 100
typedef struct TreeNode {
	int value;//����е�����Ԫ��
	bool isEmpty;//����Ƿ�Ϊ��
}TreeNode;
TreeNode t[MaxSize];//��̬˳��洢������
int n;//��¼�������

void TreeInit() {//��ʼ��
	for (int i = 0; i < MaxSize; ++i)
		t[i].isEmpty = true;//��ÿ�����״̬��Ϊ��
	return;
}

bool Have_LeftChild(int i) {//�жϽ��i�Ƿ�������
	return (2 * i <= n && !t[2 * i].isEmpty) ? true : false;
}

bool Have_RightChild(int i) {//�жϽ��i�Ƿ����Һ���
	return (2 * i + 1 <= n && !t[2 * i + 1].isEmpty) ? true : false;
}

bool Is_Leaf(int i) {//�жϽ��i�Ƿ�ΪҶ�ӽ��
	return i > (n / 2) ? true : false;
}

typedef struct Elemtype {//����������
	int value;//ֻ��һ��int����
}Elemtype;
typedef struct BiTNode {//����������
	Elemtype data;//������
	struct BiTNode* lchild, * rchild;//���Һ���ָ��
//	struct BiTNode* parent;//���ڵ�ָ�루����ʵ����Ҫ�����Ƿ���ӣ�
}BiTNode, * BiTree;

BiTree root = NULL;//����һ�ÿ���
void InitBiTree() {//��ʼ�������
	root = (BiTree)malloc(sizeof(BiTNode));
	root->data = { 1 };
//	root->parent = NULL;
	root->lchild = NULL;
	root->rchild = NULL;
	return;
}
void InsertRLChild() {//�����½ڵ㣨���������ӣ�
	BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode));
	p->data = { 2 };
	p->lchild = NULL;
	p->rchild = NULL;
	root->lchild = p;
//	p->parent = root;
	return;
}

int main() {

	return 0;
}