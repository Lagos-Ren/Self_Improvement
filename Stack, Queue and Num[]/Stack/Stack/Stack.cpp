#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define MaxSize 10
typedef struct {//˳��ջ�Ķ���
	int data[MaxSize];//��̬������ջ��Ԫ��
	int top;//ջ��ָ��
}SqStack;

void InitSqStack(SqStack& S) {//��ʼ��˳��ջ
	S.top = -1;//��ʼ��ջ��ָ��
	return;
}

bool StackEmpty(SqStack& S) {//�ж�ջ��
	return S.top == -1 ? true : false;
}

bool Push(SqStack& S, int x) {//��Ԫ����ջ
	if (S.top == MaxSize - 1)return false;//ջ������
	S.data[++S.top] = x;//ջ��ָ���ȼ�1��������Ԫ����ջ
	return true;
}

bool Pop(SqStack& S, int& x) {//��ջ����������x����ջ��Ԫ��
	if (S.top == -1)return false;//ջ�ձ���
	x = S.data[S.top--];//x��¼ջ��Ԫ�أ���ջ��ָ���1
	return true;
}

bool GetTop(SqStack& S, int& x) {//��ȡջ��Ԫ��
	if (S.top == -1)return false;//ջ�ձ���
	x = S.data[S.top];//x��¼ջ��Ԫ��
	return true;
}

typedef struct {
	int data[MaxSize];
	int top0;//0��ջջ��ָ��
	int top1;//1��ջջ��ָ��
}ShStack;//���干��ջ

void InitShStack(ShStack& S) {
	S.top0 = -1, S.top1 = MaxSize;//��ʼ������ջ����ջ��ָ��
	return;
}
//����ջջ��������top0+1 == top1

typedef struct Linknode{
	int data;
	struct Linknode* next;
}*LiStack;//��ջ�Ķ���

int main() {


	return 0;
}