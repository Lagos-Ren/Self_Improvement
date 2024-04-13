#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
using namespace std;
#define LNode LLNode
#define LinkList LLinkList
#define DNode DLNode
#define DLinkList DLLinkList

typedef struct LNode {//ѭ��������
	int data;
	struct LNode* next;
}LNode, * LinkList;

bool InitLLinkList(LinkList& L) {//ѭ���������ʼ��
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL)return false;
	L->next = L;//��ʼ״̬ͷ����nextָ��ָ��ͷ�������
	return true;
}

bool LEmpty(LinkList& L) {//ѭ���������п�
	return L->next == L ? true : false;
}

bool LisTail(LinkList& L, LNode* p) {//�ж�p����Ƿ�Ϊѭ��������ı�β���
	return p->next == L ? true : false;
}

typedef struct DNode {
	int data;
	struct DNode* prior, * next;
}DNode, * DLinkList;

bool InitDLinkList(DLinkList& L) {//ѭ��˫�����ʼ��
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL)return false;
	L->prior = L, L->next = L;//��ʼ״̬ͷ����ǰ�����̾�Ϊ����
	return true;
}

bool DisEmpty(DLinkList& L) {//ѭ��˫�����п�
	return L->next == L ? true : false;
}

bool DisTail(DLinkList& L, DNode* p) {//�ж�p����Ƿ�Ϊѭ��˫����ı�β���
	return p->next == L ? true : false;
}

bool InsertDNextNode(DNode* p, DNode* s) {//��ѭ��˫������p�������s���
	if (p == NULL || s == NULL)return false;
	s->next = p->next;//s�ĺ��ָ��p�ĺ��
	p->next->prior = s;//p�ĺ�̵�ǰ��ָ��s����ʱ���õ���p�Ǳ�β�����
	p->next = s;//p�ĺ��ָ��s
	s->prior = p;//s��ǰ��ָ��p����ɲ���
	return true;
}

bool DeleteDNode(DNode* p) {//ɾ��ѭ��˫������p����һ�����q
	DNode* q = p->next;
	q->next->prior = p;//��ʱҲ���õ���q�Ǳ�β���
	p->next = q->next;
	free(q);
	return true;
}

#define MaxSize 10
typedef struct{//��̬����
	int data;
	int next=-2;//�α꣬��next�����һ�����������±�
}SLinkList[MaxSize];
SLinkList a;//��ȻЧ���ϵȼۣ���������д���ɶ��Ը�ǿ
/*
�ȼ���
typedef struct SNode{
	int data;
	int next;
}SNode;
SNode a[MaxSize];
*/

int main() {


	return 0;
}