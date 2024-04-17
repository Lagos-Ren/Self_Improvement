#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define MaxSize 10
typedef struct {//定义顺序存储结构的队列
	int data[MaxSize];//用静态数组存放队列元素
	int front, rear;//队头指针和队尾指针
}SqQueue;

void InitSqQueue(SqQueue& Q) {//初始化队列
	Q.front = Q.rear = 0;//初始时，队头、队尾指针都指向0
	return;
}

bool QueueEmpty(SqQueue& Q) {//判断队列是否为空
	return Q.rear == Q.front ? true : false;
}

bool EnSqQueue(SqQueue& Q, int x) {//入队
	if ((Q.rear + 1) % MaxSize == Q.front)return false;//若队列已满则报错
	Q.data[Q.rear] = x;//将x插入队尾
	Q.rear = (Q.rear + 1) % MaxSize;//队尾指针加1取模
	//用模运算将存储空间在逻辑上变成了环状
	return true;
}

bool DeSqQueue(SqQueue& Q, int& x) {//出队（删除一个队头元素，并用x返回）
	if (Q.rear == Q.front)return false;//若队空则报错
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;//队头指针后移一位
	return true;
}

bool GetHead(SqQueue& Q, int& x) {//获得队头元素的值，并用x返回
	if (Q.rear == Q.front)return false;//队空则报错
	x = Q.data[Q.front];
	return true;
}

//队列的链式实现
typedef struct LinkNode{//链式队列每个结点的定义
	int data;
	struct LinkNode* next;
}LinkNode;
typedef struct {//链式队列的定义，只需有头指针和尾指针即可
	LinkNode* front, * rear;
}LinkQueue;

void InitQueue(LinkQueue& Q) {//初始化队列（带头结点）
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));//初始时头尾指针都指向头结点
	Q.front->next = NULL;
	return;
}

bool IsEmpty(LinkQueue& Q) {//判断队列是否为空
	return Q.front == Q.rear ? true : false;
}

bool EnQueue(LinkQueue& Q, int x) {//新元素入队
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL)return false;
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;//将s插入队尾
	Q.rear = s;//队尾指针指向s
	return true;
}

bool DeQueue(LinkQueue& Q, int& x) {//队头元素出队（带头结点）
	if (IsEmpty(Q))return false;//空队报错
	LinkNode* p = Q.front->next;
	x = p->data;//用x返回队头元素数据
	Q.front->next = p->next;//修改队头结点的next指针，指向队头元素的后继
	if (Q.rear == p)Q.rear = Q.front;//若被删除结点是队尾结点，则修改rear指针
	free(p);//释放结点空间
	return true;
}


/*
void Init(LinkQueue& Q) {//初始化队列（不带头结点）
	Q.front = NULL, Q.rear = NULL;
	return;
}
bool Is_Empty(LinkQueue& Q) {//判断队列是否为空（不带头结点）
	return Q.front == NULL ? true : false;
}
bool EnQueue(LinkQueue& Q, int x) {//新元素入队（不带头结点）
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL)return false;
	s->data = x;
	s->next = NULL;
	if (Is_Empty(Q)) {//不带头结点时需要对第一个元素进行特殊处理
		Q.front = s;//空队列中插入第一个元素
		Q.rear = s;//修改队头队尾指针
	}
	else {
		Q.rear->next = s;//将s插入队尾
		Q.rear = s;//队尾指针指向s
	}
	return true;
}
bool DeQueue(LinkQueue& Q, int& x) {//队头元素出队（不带头结点）
	if (Is_Empty(Q))return false;//空队报错
	LinkNode* p = Q.front;//p指向此次出队的结点
	x = p->data;//用x返回队头元素数据
	Q.front = p->next;//修改队头指针，指向队头元素的后继
	if (Q.rear == p)Q.front = NULL, Q.rear = NULL;//若被删除结点是队尾结点，则头尾指针都指向NULL
	free(p);//释放结点空间
	return true;
}
*/



int main() {

	return 0;
}