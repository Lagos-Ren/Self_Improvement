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

bool EnQueue(SqQueue& Q, int x) {//入队
	if ((Q.rear + 1) % MaxSize == Q.front)return false;//若队列已满则报错
	Q.data[Q.rear] = x;//将x插入队尾
	Q.rear = (Q.rear + 1) % MaxSize;//队尾指针加1取模
	//用模运算将存储空间在逻辑上变成了环状
	return true;
}

bool DeQueue(SqQueue& Q, int& x) {//出队（删除一个队头元素，并用x返回）
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

int main() {

	return 0;
}