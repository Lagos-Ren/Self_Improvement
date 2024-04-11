//80分代码，最后两个数据点TLE
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

/*
//满分代码，但是自己写的野鸡写法
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int MAXN = 1e6+7;

struct List{
	int data=0;
	int next=0;//因为本体没有重复数据元素，所以直接用next记录下一个结点
}L[MAXN];

inline int qread(){//快读
	int x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*w;
}

inline void Insert(int x,int y){
	L[y].next=L[x].next;
	L[x].next=y;
	L[y].data=y;
	return;
}

inline void Find(int x){
	if(L[x].next==0)printf("0\n");
	else{
		int y=L[x].next;
		printf("%d\n",L[y].data);
	}
	return;
}

inline void Del(int x){
	int y=L[x].next;
	L[y].data=0;
	L[x].next=L[y].next;
	L[y].next=0;
	return;
}

int main(){
	int p,q,x,y;
	p=qread();
	L[1].data=1;
	while(p--){
		q=qread();
		switch(q){
			case 1:x=qread(),y=qread();Insert(x,y);break;
			case 2:x=qread();Find(x);break;
			case 3:x=qread();Del(x);break;
			default:break;
		}
	}
	return 0;
}
*/