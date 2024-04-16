#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define MaxSize 10
typedef struct {//����˳��洢�ṹ�Ķ���
	int data[MaxSize];//�þ�̬�����Ŷ���Ԫ��
	int front, rear;//��ͷָ��Ͷ�βָ��
}SqQueue;

void InitSqQueue(SqQueue& Q) {//��ʼ������
	Q.front = Q.rear = 0;//��ʼʱ����ͷ����βָ�붼ָ��0
	return;
}

bool QueueEmpty(SqQueue& Q) {//�ж϶����Ƿ�Ϊ��
	return Q.rear == Q.front ? true : false;
}

bool EnQueue(SqQueue& Q, int x) {//���
	if ((Q.rear + 1) % MaxSize == Q.front)return false;//�����������򱨴�
	Q.data[Q.rear] = x;//��x�����β
	Q.rear = (Q.rear + 1) % MaxSize;//��βָ���1ȡģ
	//��ģ���㽫�洢�ռ����߼��ϱ���˻�״
	return true;
}

bool DeQueue(SqQueue& Q, int& x) {//���ӣ�ɾ��һ����ͷԪ�أ�����x���أ�
	if (Q.rear == Q.front)return false;//���ӿ��򱨴�
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;//��ͷָ�����һλ
	return true;
}

bool GetHead(SqQueue& Q, int& x) {//��ö�ͷԪ�ص�ֵ������x����
	if (Q.rear == Q.front)return false;//�ӿ��򱨴�
	x = Q.data[Q.front];
	return true;
}

int main() {

	return 0;
}