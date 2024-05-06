#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

#define MAX_TREE_SIZE 100
typedef struct ElemType {
	int value;
}ElemType;//Ԥ����

typedef struct {
	ElemType data;
	int parent;//˫��λ����
}PTNode;
typedef struct {//�������Ͷ���
	PTNode nodes[MAX_TREE_SIZE];//˫�ױ�ʾ
	int n;//�����
}PTree;

struct CTNode {//������Bվ��Ļ˵���ڽӱ�
	int child;//���ӽڵ��������е�λ��
	struct CTNode* next;//��һ������
};
typedef struct {
	ElemType data;
	struct CTNode* firstChild;//��һ������
}CTBox;
typedef struct {
	CTBox nodes[MAX_TREE_SIZE];//���ӱ�ʾ��
	int n, r;//������͸���λ��
}CTree;

typedef struct CSNode {//�����ֵܱ�ʾ��
	ElemType data;//������
	struct CSNode* firstchild, * nextsibling;//��һ�����Ӻ����ֵ�ָ��
}CSNode, * CSTree;

void Visit(CSNode* T) {
	cout << T->data.value << " ";
	return;
}

void PreOrder(CSTree T) {//�ȸ�������ʹ�ú����ֵܱ�ʾ����
	if (T != NULL) {
		Visit(T);//���ʸ����
		CSTree C = T->firstchild;//C��¼��ǰ�������ĵ�һ������
		do {//���ȶ���CΪ�������������ȸ�����
			PreOrder(C);
			C = C->nextsibling;//�����ζ�C�����ֵ�Ϊ�������������ȸ�����
		} while (C != NULL);//��C�����������ֵ�ʱѭ������
	}
	return;
}

void PostOrder(CSTree T) {//�������
	if (T != NULL) {
		CSTree C = T->firstchild;
		do {
			PostOrder(C);//����CΪ���������������
			C = C->nextsibling;//���η���C�����ֵܽ��
		} while (C != NULL);
		Visit(T);//�����ʸ����
	}
	return;
}


int main() {


	return 0;
}