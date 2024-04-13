#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
using namespace std;
#define LNode LLNode
#define LinkList LLinkList
#define DNode DLNode
#define DLinkList DLLinkList

typedef struct LNode {//循环单链表
	int data;
	struct LNode* next;
}LNode, * LinkList;

bool InitLLinkList(LinkList& L) {//循环单链表初始化
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL)return false;
	L->next = L;//初始状态头结点的next指针指向头结点自身
	return true;
}

bool LEmpty(LinkList& L) {//循环单链表判空
	return L->next == L ? true : false;
}

bool LisTail(LinkList& L, LNode* p) {//判断p结点是否为循环单链表的表尾结点
	return p->next == L ? true : false;
}

typedef struct DNode {
	int data;
	struct DNode* prior, * next;
}DNode, * DLinkList;

bool InitDLinkList(DLinkList& L) {//循环双链表初始化
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL)return false;
	L->prior = L, L->next = L;//初始状态头结点的前驱与后继均为自身
	return true;
}

bool DisEmpty(DLinkList& L) {//循环双链表判空
	return L->next == L ? true : false;
}

bool DisTail(DLinkList& L, DNode* p) {//判断p结点是否为循环双链表的表尾结点
	return p->next == L ? true : false;
}

bool InsertDNextNode(DNode* p, DNode* s) {//在循环双链表中p结点后插入s结点
	if (p == NULL || s == NULL)return false;
	s->next = p->next;//s的后继指向p的后继
	p->next->prior = s;//p的后继的前驱指向s，此时不用担心p是表尾结点了
	p->next = s;//p的后继指向s
	s->prior = p;//s的前驱指向p，完成插入
	return true;
}

bool DeleteDNode(DNode* p) {//删除循环双链表结点p的下一个结点q
	DNode* q = p->next;
	q->next->prior = p;//此时也不用担心q是表尾结点
	p->next = q->next;
	free(q);
	return true;
}

#define MaxSize 10
typedef struct{//静态链表
	int data;
	int next=-2;//游标，用next存放下一个结点的数组下标
}SLinkList[MaxSize];
SLinkList a;//虽然效果上等价，但是这种写法可读性更强
/*
等价于
typedef struct SNode{
	int data;
	int next;
}SNode;
SNode a[MaxSize];
*/

int main() {


	return 0;
}