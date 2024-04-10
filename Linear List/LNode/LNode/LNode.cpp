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
bool NHListInsert(LinkList& L, int i, int e);
void Nohead();

bool InitList(LinkList& L) {//带头结点的初始化（绝大多数情况下）
	L = (LNode*)malloc(sizeof(LNode));//分配一个头结点
	if (L == NULL)return false;//内存不足，分配失败
	L->next = NULL;//头节点后暂无节点
	return true;//分配成功，返回值为true
}

bool ListInsert(LinkList& L, int i, int e) {//按位插入，在第i个位置插入元素e（带头结点）
	if (i < 1)return false;//排除不合法的i
	LNode* p;//临时指针
	int j = 0;//表示p指向第j个结点
	p = L;//p初始状态和头结点指向同一位置，可视作第0个结点（不存数据）
	while (p != NULL && j < i - 1) {//循环找到第i-1个结点
		p = p->next;
		++j;
	}
//	上面的while等价于：（自己瞎写的）
//	LNode* p = L;
//	for (int j = 0; p != NULL && j < i - 1; p = p->next, ++j);
//	后面一段可以直接等价于下面一行代码：（当然要先声明后插函数）
//	return InsertNextNode(p,e);
	if (p == NULL)return false;//i值不合法
	LNode* s = (LNode*)malloc(sizeof(LNode));//申请一个新结点
	s->data = e;//插值
	s->next = p->next;//将p结点的下一个指向传给s
	p->next = s;//然后将p指向s，完成s的插入
	return true;
}

bool InsertNextNode(LNode* p, int e) {//对给定结点进行后插操作（在后面插入一个数据）
	if (p == NULL)return false;//判断节点是否合法
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)return false;//内存分配失败
	s->data = e;//基本逻辑同按位插入
	s->next = p->next;
	p->next = s;
	return true;
}

bool InsertPriorNode(LNode* p, int e) {//对给定结点进行前插操作（在前面插入一个数据）
	if (p == NULL)return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)return false;
	s->next = p->next;//将s的后继指向p的后继
	p->next = s;//p指向s，完成将s插入链表
	s->data = p->data;//将p的数据赋给s
	p->data = e;//再把需要插入的值e赋给p，从而完成变相的“前插”
	return true;
}

bool ListDelete(LinkList& L, int i, int& e) {//按位删除：删除第i位序的元素，并用e返回其值
	if (i < 1)return false;
	LNode* p = L;
	for (int j = 0; p != NULL && j < i - 1; p = p->next, ++j);//循环查找第i-1个结点，逻辑同按位插入
	if (p == NULL || p->next == NULL)return false;//若第i-1个结点后无结点也非法（即不存在i结点）
	LNode* q = p->next;//令q指向被删除结点
	e = q->data;//用e返回被删除的值
	p->next = q->next;//用p的后继继承q的后继，从而将q从链表中断开
	free(q);//释放内存空间，完成删除操作
	return true;
}

bool DeleteNode(LNode* p) {//删除指定结点p
	if (p == NULL)return false;
	if (p->next != NULL) {//如果p不是表尾结点
		LNode* q = p->next;//令q指向p的后继结点
		p->data = q->data;//将p结点的数据用后继结点的数据覆盖
		p->next = q->next;//再将p的后继指向p的后继的后继，从而实现q结点的断开
		free(q);//此时p的位置实际上已经是q，p已经被删，所以释放q即可（思想类似前插）
	}else free(p);
	//如果p是表尾结点则直接释放p
	//但是单链表的相应信息也要变化，比如len--，这里就需要使用全局变量或者将参数传入函数
	//具体实现可能较为复杂，视情况而定
	return true;
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

bool NHListInsert(LinkList& L, int i, int e) {//不带头结点的按位插入
	if (i < 1)return false;
	if (i == 1) {//需要单独为第1位序的结点开辟一个逻辑，比较麻烦
		LNode* s = (LNode*)malloc(sizeof(LNode));//申请新节点
		s->data = e;//赋值
		s->next = L;//新节点后接原表L
		L = s;//头结点变为s
		return true;
	}
	else return ListInsert(L, i-1, e);//其他位置的插入同带头结点
}

void Nohead() {//不带头结点的单链表
	//不带头结点，L.data中存放数据；带头结点，L.data中不存数据，即可视为第0个节点
	LinkList L;//声明一个指向单链表的指针
	NHInitList(L);//初始化一个空表
	//……然后进行后续操作
	return;
}