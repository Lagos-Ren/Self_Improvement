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



int main() {

	return 0;
}