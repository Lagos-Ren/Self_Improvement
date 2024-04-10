#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
using namespace std;

typedef struct LNode {//typedef关键字：重命名关键字，使代码更简洁
	//此处等价于typedef struct LNode LNode;
	int data;
	struct LNode* next;//指针指向下一个节点
}LNode, *LinkList;//此处等价于typedef struct LNode *LinkList;

LNode* GetElem(LinkList L, int i) {//按位查找
	//LNode*强调这是一个节点，LinkList强调这是一个单链表，需根据实际情况编写代码以增强可读性
	if (i == 0)return L;//头节点直接返回
	if (i < 1)return NULL;//若i不合法返回NULL
	int j=1;
	LNode* p = L->next;//初始值为头结点
	while (p != NULL && j < i) {//从头按位序依次查找
		p = p->next;
		++j;
	}
	return p;//返回对应位序节点
}

bool IsEmpty(LinkList& L) {//判断单链表是否为空
	return L == NULL ? true : false;
}

bool NHInitList(LinkList& L);
void Nohead();

bool InitList(LinkList& L) {//带头结点的初始化（绝大多数情况下）
	L = (LNode*)malloc(sizeof(LNode));//分配一个头结点
	if (L == NULL)return false;//内存不足，分配失败
	L->next = NULL;//头节点后暂无节点
	return true;//分配成功，返回值为true
}


int main() {
	LinkList L;//声明头指针（指向单链表第一个结点的指针），等价于LNode *L;
	InitList(L);
	
	return 0;
}

bool NHInitList(LinkList& L) {//初始化单链表（不带头结点）
	L = NULL;
	return true;
}

void Nohead() {//不带头结点的单链表
	LinkList L;//声明一个指向单链表的指针
	NHInitList(L);//初始化一个空表
	//……然后进行后续操作
	return;
}