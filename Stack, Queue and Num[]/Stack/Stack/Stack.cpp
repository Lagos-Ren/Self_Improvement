#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define MaxSize 10
typedef struct {//顺序栈的定义
	int data[MaxSize];//静态数组存放栈中元素
	int top;//栈顶指针
}SqStack;

void InitSqStack(SqStack& S) {//初始化顺序栈
	S.top = -1;//初始化栈顶指针
	return;
}

bool StackEmpty(SqStack& S) {//判断栈空
	return S.top == -1 ? true : false;
}

bool Push(SqStack& S, int x) {//新元素入栈
	if (S.top == MaxSize - 1)return false;//栈满报错
	S.data[++S.top] = x;//栈顶指针先加1，再让新元素入栈
	return true;
}

bool Pop(SqStack& S, int& x) {//出栈操作，并用x返回栈顶元素
	if (S.top == -1)return false;//栈空报错
	x = S.data[S.top--];//x记录栈顶元素，再栈顶指针减1
	return true;
}

bool GetTop(SqStack& S, int& x) {//读取栈顶元素
	if (S.top == -1)return false;//栈空报错
	x = S.data[S.top];//x记录栈顶元素
	return true;
}

typedef struct {
	int data[MaxSize];
	int top0;//0号栈栈顶指针
	int top1;//1号栈栈顶指针
}ShStack;//定义共享栈

void InitShStack(ShStack& S) {
	S.top0 = -1, S.top1 = MaxSize;//初始化共享栈两个栈顶指针
	return;
}
//共享栈栈满条件：top0+1 == top1

typedef struct Linknode{
	int data;
	struct Linknode* next;
}*LiStack;//链栈的定义

int main() {


	return 0;
}