#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
using namespace std;

typedef struct LNode {//typedef�ؼ��֣��������ؼ��֣�ʹ��������
	//�˴��ȼ���typedef struct LNode LNode;
	int data;
	struct LNode* next;//ָ��ָ����һ���ڵ�
}LNode, *LinkList;//�˴��ȼ���typedef struct LNode *LinkList;

LNode* GetElem(LinkList L, int i) {//��λ����
	//LNode*ǿ������һ���ڵ㣬LinkListǿ������һ�������������ʵ�������д��������ǿ�ɶ���
	if (i == 0)return L;//ͷ�ڵ�ֱ�ӷ���
	if (i < 1)return NULL;//��i���Ϸ�����NULL
	int j=1;
	LNode* p = L->next;//��ʼֵΪͷ���
	while (p != NULL && j < i) {//��ͷ��λ�����β���
		p = p->next;
		++j;
	}
	return p;//���ض�Ӧλ��ڵ�
}

bool IsEmpty(LinkList& L) {//�жϵ������Ƿ�Ϊ��
	return L == NULL ? true : false;
}

bool NHInitList(LinkList& L);
void Nohead();

bool InitList(LinkList& L) {//��ͷ���ĳ�ʼ���������������£�
	L = (LNode*)malloc(sizeof(LNode));//����һ��ͷ���
	if (L == NULL)return false;//�ڴ治�㣬����ʧ��
	L->next = NULL;//ͷ�ڵ�����޽ڵ�
	return true;//����ɹ�������ֵΪtrue
}


int main() {
	LinkList L;//����ͷָ�루ָ�������һ������ָ�룩���ȼ���LNode *L;
	InitList(L);
	
	return 0;
}

bool NHInitList(LinkList& L) {//��ʼ������������ͷ��㣩
	L = NULL;
	return true;
}

void Nohead() {//����ͷ���ĵ�����
	LinkList L;//����һ��ָ�������ָ��
	NHInitList(L);//��ʼ��һ���ձ�
	//����Ȼ����к�������
	return;
}