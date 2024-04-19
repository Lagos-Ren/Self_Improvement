#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>//����������ر�ͷ�ļ�
#define ull unsigned long long//��ull�滻unsigned long long�ô�������
using namespace std;

typedef struct SNode{
	int len;//��¼����ջ��Ԫ�ظ�����
	ull data;//��¼����Ԫ��
	struct SNode* next;
}SNode,* SqStack;//��������ʽ����ջ

inline void InitStack(SqStack& S) {//��ʼ��ջ
	S = (SNode*)malloc(sizeof(SNode));//����ͷ���
	S->next = NULL;
	S->len = 0;//��ʼ��Ϊ0
	return;
}

inline bool StackEmpty(SqStack& S) {//�п�
	return S->len == 0 ? true : false;//��Ϊ0��Ϊ��ջ
}

inline void Push(SqStack& S, ull x) {//��ջ
	SNode* p = (SNode*)malloc(sizeof(SNode));//�����½��
	if (p == NULL)return;//����ʧ��
	p->data = x;//��¼������
	p->next = S->next;//���½ڵ�p�ĺ��ָ��ջ��Ԫ�صĺ��
	S->next = p;//ջ��Ԫ�صĺ����ָ��p����ɲ���
	S->len++;//��+1
	return;
}

inline void Pop(SqStack& S) {//��ջ
	if (StackEmpty(S))printf("Empty\n");//����Ϊ0��Ϊ��ջ�������������Empty��
	else {
		SNode* p = S->next;//��������ʱ���pָ��ջ��Ԫ��
		S->next = p->next;//ջ��Ԫ�صĺ��ָ�����̵ĺ��
		free(p);//�ͷ�ջ��Ԫ�أ���ɳ�ջ
		S->len--;//��-1
	}
	return;
}

inline void Query(SqStack& S) {//ѯ��ջ��Ԫ��
	if (StackEmpty(S))printf("Anguei!\n");//����Ϊ0��Ϊ��ջ�������������Anguei!��
	else printf("%llu\n", S->next->data);//�������ջ��Ԫ������
	return;
}

int main() {
	int T,n;
	std::cin >> T;//std������
	string str;//��¼�����ַ���
	ull x;
	for (int i = 1; i <= T; ++i) {//T������
		std::cin >> n;
		SqStack S;//����һ��ջ
		InitStack(S);
		for (int j = 1; j <= n; ++j) {//n�β���
			std::cin >> str;//std�����������ո�ֹͣ����һ���scanf����
			if (str == "push") {//��Ϊpush���������ջ����
				std::cin >> x;
				Push(S, x);
			}
			else if (str == "pop") {//��Ϊpop������г�ջ����
				Pop(S);
			}
			else if (str == "query") {//��Ϊquery�������ѯ��ջ��Ԫ�ز���
				Query(S);
			}
			else if (str == "size") {//��Ϊsize���������
				printf("%d\n", S->len);
			}
		}
	}
	return 0;
}