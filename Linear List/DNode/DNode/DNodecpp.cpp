#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

typedef struct DNode {
	int data;
	DNode* prior, * next;
}DNode, * DLinkList;

bool InitDLinkList(DLinkList& L) {//��ʼ��˫����
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL)return false;
	L->prior = NULL, L->next = NULL;//ͷ����ǰ����Զָ��NULL
	return true;
}

bool IsEmpty(DLinkList& L) {//�ж�˫�����Ƿ�Ϊ��
	return L->next == NULL ? true : false;
}

DNode* GetElem(DLinkList& L,int e) {//��ֵ�������ݣ�������Ӧ��㣨ͬ������
	DNode* r = L;
	for (; r->next != NULL && r->data != e; r = r->next);
	return r;
}

DNode* FindElem(DLinkList& L, int i) {//��λ�������ݣ�������Ӧ��㣨��ͷ��㣬ͬ������
	if (i < 1)return NULL;//�ж�i�Ƿ�Ϸ�
	int j = 0;
	DNode* r = L;
	for (; r->next != NULL && j < i; r = r->next, ++j);//�ӱ�ͷ��ʼ����
	return r;
}

bool InsertNextDNode(DNode* p, DNode* s) {//��s���嵽p���֮��
	if (p == NULL || s == NULL)return false;//�ų��Ƿ�����
	s->next = p->next;//s�ĺ��ָ��p�ĺ��
	if (p->next != NULL)p->next->prior = s;//���p����к�̣���p�ĺ�̵�ǰ��ָ��s
	s->prior = p;//s��ǰ��ָ��p
	p->next = s;//p�ĺ��ָ��s����ɲ���
	return true;
}

bool InsertPriorDNode(DNode* p, DNode* s) {//��s���嵽p���֮ǰ
	if (p == NULL || s == NULL)return false;
	s->prior = p->prior;
	p->prior->next = s;//���p�ǵ�һλ���㣬��p��ǰ��������ͷָ��L�����Բ�����NULL�����
	s->next = p;
	p->prior = s;
	return true;
}

bool InsertDNode(DLinkList& L,DNode* p, int i) {//��p�嵽��i��λ��
	return InsertNextDNode(p, FindElem(L, i - 1));
	//ֱ�ӵ��ð�λ���Һ����ͺ�庯�����ҵ���i-1λ��Ľ�㣬����������p
}

bool DeleteNextDNode(DNode* p) {//ɾ��p�ĺ�̽��
	if (p == NULL || p->next == NULL)return false;//�ж�p�Ƿ�Ϸ��Լ�p�Ƿ��к�̽��
	DNode* q = p->next;
	p->next = q->next;//��p�ĺ����q�ĺ���滻
	if (q->next != NULL)q->next->prior = p;//��q�к�̽�㣬��q�ĺ�̵�ǰ����p�滻
	free(q);//�ͷ�q���
	return true;
}

void DestoryList(DLinkList& L) {//����˫������
	while (L->next != NULL)DeleteNextDNode(L);
	free(L);
	L = NULL;
	return;
}

int main() {
	DLinkList L;
	InitDLinkList(L);



	return 0;
}