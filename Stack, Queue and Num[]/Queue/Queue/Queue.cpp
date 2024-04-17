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

bool EnSqQueue(SqQueue& Q, int x) {//���
	if ((Q.rear + 1) % MaxSize == Q.front)return false;//�����������򱨴�
	Q.data[Q.rear] = x;//��x�����β
	Q.rear = (Q.rear + 1) % MaxSize;//��βָ���1ȡģ
	//��ģ���㽫�洢�ռ����߼��ϱ���˻�״
	return true;
}

bool DeSqQueue(SqQueue& Q, int& x) {//���ӣ�ɾ��һ����ͷԪ�أ�����x���أ�
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

//���е���ʽʵ��
typedef struct LinkNode{//��ʽ����ÿ�����Ķ���
	int data;
	struct LinkNode* next;
}LinkNode;
typedef struct {//��ʽ���еĶ��壬ֻ����ͷָ���βָ�뼴��
	LinkNode* front, * rear;
}LinkQueue;

void InitQueue(LinkQueue& Q) {//��ʼ�����У���ͷ��㣩
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));//��ʼʱͷβָ�붼ָ��ͷ���
	Q.front->next = NULL;
	return;
}

bool IsEmpty(LinkQueue& Q) {//�ж϶����Ƿ�Ϊ��
	return Q.front == Q.rear ? true : false;
}

bool EnQueue(LinkQueue& Q, int x) {//��Ԫ�����
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL)return false;
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;//��s�����β
	Q.rear = s;//��βָ��ָ��s
	return true;
}

bool DeQueue(LinkQueue& Q, int& x) {//��ͷԪ�س��ӣ���ͷ��㣩
	if (IsEmpty(Q))return false;//�նӱ���
	LinkNode* p = Q.front->next;
	x = p->data;//��x���ض�ͷԪ������
	Q.front->next = p->next;//�޸Ķ�ͷ����nextָ�룬ָ���ͷԪ�صĺ��
	if (Q.rear == p)Q.rear = Q.front;//����ɾ������Ƕ�β��㣬���޸�rearָ��
	free(p);//�ͷŽ��ռ�
	return true;
}


/*
void Init(LinkQueue& Q) {//��ʼ�����У�����ͷ��㣩
	Q.front = NULL, Q.rear = NULL;
	return;
}
bool Is_Empty(LinkQueue& Q) {//�ж϶����Ƿ�Ϊ�գ�����ͷ��㣩
	return Q.front == NULL ? true : false;
}
bool EnQueue(LinkQueue& Q, int x) {//��Ԫ����ӣ�����ͷ��㣩
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL)return false;
	s->data = x;
	s->next = NULL;
	if (Is_Empty(Q)) {//����ͷ���ʱ��Ҫ�Ե�һ��Ԫ�ؽ������⴦��
		Q.front = s;//�ն����в����һ��Ԫ��
		Q.rear = s;//�޸Ķ�ͷ��βָ��
	}
	else {
		Q.rear->next = s;//��s�����β
		Q.rear = s;//��βָ��ָ��s
	}
	return true;
}
bool DeQueue(LinkQueue& Q, int& x) {//��ͷԪ�س��ӣ�����ͷ��㣩
	if (Is_Empty(Q))return false;//�նӱ���
	LinkNode* p = Q.front;//pָ��˴γ��ӵĽ��
	x = p->data;//��x���ض�ͷԪ������
	Q.front = p->next;//�޸Ķ�ͷָ�룬ָ���ͷԪ�صĺ��
	if (Q.rear == p)Q.front = NULL, Q.rear = NULL;//����ɾ������Ƕ�β��㣬��ͷβָ�붼ָ��NULL
	free(p);//�ͷŽ��ռ�
	return true;
}
*/



int main() {

	return 0;
}