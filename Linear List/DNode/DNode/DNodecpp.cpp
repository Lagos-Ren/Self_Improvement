#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

typedef struct DNode {
	int data;
	DNode* prior, * next;
}DNode, * DLinkList;

bool InitDLinkList(DLinkList& L) {//初始化双链表
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL)return false;
	L->prior = NULL, L->next = NULL;//头结点的前驱永远指向NULL
	return true;
}

bool IsEmpty(DLinkList& L) {//判断双链表是否为空
	return L->next == NULL ? true : false;
}

DNode* GetElem(DLinkList& L,int e) {//按值查找数据，返回相应结点（同单链表）
	DNode* r = L;
	for (; r->next != NULL && r->data != e; r = r->next);
	return r;
}

DNode* FindElem(DLinkList& L, int i) {//按位查找数据，返回相应结点（带头结点，同单链表）
	if (i < 1)return NULL;//判断i是否合法
	int j = 0;
	DNode* r = L;
	for (; r->next != NULL && j < i; r = r->next, ++j);//从表头开始遍历
	return r;
}

bool InsertNextDNode(DNode* p, DNode* s) {//将s结点插到p结点之后
	if (p == NULL || s == NULL)return false;//排除非法参数
	s->next = p->next;//s的后继指向p的后继
	if (p->next != NULL)p->next->prior = s;//如果p结点有后继，则p的后继的前驱指向s
	s->prior = p;//s的前驱指向p
	p->next = s;//p的后继指向s，完成插入
	return true;
}

bool InsertPriorDNode(DNode* p, DNode* s) {//将s结点插到p结点之前
	if (p == NULL || s == NULL)return false;
	s->prior = p->prior;
	p->prior->next = s;//如果p是第一位序结点，则p的前驱将会是头指针L，所以不存在NULL的情况
	s->next = p;
	p->prior = s;
	return true;
}

bool InsertDNode(DLinkList& L,DNode* p, int i) {//将p插到第i个位置
	return InsertNextDNode(p, FindElem(L, i - 1));
	//直接调用按位查找函数和后插函数，找到第i-1位序的结点，在其后插入结点p
}

bool DeleteNextDNode(DNode* p) {//删除p的后继结点
	if (p == NULL || p->next == NULL)return false;//判断p是否合法以及p是否有后继结点
	DNode* q = p->next;
	p->next = q->next;//将p的后继用q的后继替换
	if (q->next != NULL)q->next->prior = p;//若q有后继结点，则q的后继的前驱用p替换
	free(q);//释放q结点
	return true;
}

void DestoryList(DLinkList& L) {//销毁双向链表
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