#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

typedef struct LNode {
	int data;
	LNode* next;
}LNode, * LinkList;

void InitList(LinkList& L) {
	L = (LinkList)malloc(sizeof(LNode));
	if (L == NULL)return;
	LNode* s;
	s = (LNode*)malloc(sizeof(LNode));
	s->data = 1;
	L->next = s;
	s->next = NULL;
	return;
}

LNode* GetElem(LinkList& L, int e) {
	LNode* r = L;
	for (; r != NULL && r->data != e; r = r->next);
	if (r == NULL)return NULL;
	else return r;
}

void List_TailInsert(LinkList& L, int x, int y) {
	LNode* s, * r = GetElem(L, x);
	if (r == NULL)return;
	s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)return;
	s->data = y;
	s->next = r->next;
	r->next = s;
	return;
}

void FindNextElem(LinkList& L, int x) {
	LNode* r = GetElem(L, x);
	if (r == NULL || r->next == NULL)printf("0\n");
	else printf("%d\n", r->next->data);
	return;
}

void DeleteNextElem(LinkList& L, int x) {
	LNode* s, * r = GetElem(L, x);
	if (r == NULL || r->next == NULL)return;
	s = r->next;
	r->next = s->next;
	free(s);
	return;
}

int main() {
	int p, q, x, y;
	LinkList L;
	InitList(L);
	scanf("%d", &p);
	while (p--) {
		scanf("%d", &q);
		if (q == 1) {
			scanf("%d %d", &x, &y);
			List_TailInsert(L, x, y);
		}else if (q == 2) {
			scanf("%d", &x);
			FindNextElem(L, x);
		}else if (q == 3) {
			scanf("%d", &x);
			DeleteNextElem(L, x);
		}
	}
	return 0;
}