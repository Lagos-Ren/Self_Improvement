#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define MaxSize 100
typedef struct LNode {
	char data;
	struct LNode* next;
}LNode,*SqStack;//������ʽ����˳��ջ

void InitStack(SqStack& S) {//��ʼ��ջ
	S = (LNode*)malloc(sizeof(LNode));
	if (S == NULL)return;
	S->next = NULL;
	return;
}

bool is_Empty(SqStack& S) {//�ж�ջ�Ƿ�Ϊ��
	return S->next == NULL ? true : false;
}

bool Push(SqStack& S, char ch) {//��Ԫ����ջ
	LNode* p = (LNode*)malloc(sizeof(LNode));
	if (p == NULL)return false;
	p->data = ch;
	p->next = S->next;
	S->next = p;
	return true;
}

bool Pop(SqStack& S, char& ch) {//ջ��Ԫ�س�ջ������ch������ֵ
	if (is_Empty(S))return false;
	LNode* p = S->next;
	ch = p->data;
	S->next = p->next;
	free(p);
	return true;
}

bool Query(SqStack& S, char& ch) {//����ѯջ��Ԫ�أ���ch����
	if (is_Empty(S))return false;
	ch = S->next->data;
	return true;
}

bool is_Op(char ch) {//�ж�ch�Ƿ�Ϊ������
	if (ch == '+')return true;
	if (ch == '-')return true;
	if (ch == '/')return true;
	if (ch == '*')return true;
	if (ch == '(')return true;
	if (ch == ')')return true;
	return false;
}

bool is_Prim(char a, char b) {//�жϲ����������ȼ�����a�����ȼ�����b�򷵻�true
	if (a == '(' || a == ')')return true;
	if (a == '*' || a == '/') {
		if (b == '+' || b == '-' || b == '*' || b == '/')return true;
	}
	if (a == '+' || a == '-') {
		if (b == '+' || b == '-')return true;
	}
	return false;
}

int main() {
	int len = 0, r = 0;//len��¼��׺���ʽ���ȣ�r��¼��׺���ʽ����
	char str[MaxSize], ch;//str�ַ������¼��׺���ʽ
	char cal[MaxSize];//cal�ַ������¼��׺���ʽ
	SqStack S;//����һ��ջ
	InitStack(S);//��ʼ��ջ
	while (ch = getchar()) {//��λ������׺���ʽ
		if (ch == '\n')break;//�������з����������
		str[len++] = ch;//���򽫶������ַ������ַ�����
	}
	for (int i = 0; i < len; ++i) {//��λɨ����׺���ʽ
		if (!is_Op(str[i])) {//����ǰλΪ������
			cal[r++] = str[i];//ֱ�ӽ������������׺���ʽ
			continue;
		}
		else {//����ǰλΪ������
			if (str[i] == '(') {//��Ϊ��������ֱ��ѹ��ջ��
				Push(S, str[i]);
				continue;
			}
			else if (str[i] == ')') {//��Ϊ������
				while (!is_Empty(S)) {//����ջ�в��������γ�ջ
					Pop(S, ch);
					if (ch == '(')break;//ֱ��������Ϊֹ
					cal[r++] = ch;//����ջ�Ĳ����������׺���ʽ
				}
				continue;
			}
			else {//�Ӽ��˳������������ͬһ���߼�
				if (is_Empty(S)) {//��ջ����ֱ��ѹ��
					Push(S, str[i]);
					continue;
				}
				if (Query(S, ch)) {//������Ҫ����ǰ�������ջ��������Ա�
					while (!is_Empty(S)) {
						//��ջ�ǿգ�����Ҫ��ջ�����ȼ����ڻ���ڵ�ǰ��������������������
						//�����뵽��׺���ʽ��
						Query(S, ch);//����chΪջ�������
						if (!is_Prim(ch, str[i]))break;//��ջ����������ȼ�������ֹͣ��ջ
						Pop(S, ch);//��ջ
						if (ch == '(')break;//��Ϊ��������ֱ������ѭ������ֹ������׺���ʽ
						cal[r++] = ch;//��ջ��������������׺���ʽ
					}
				}
				Push(S, str[i]);//��󽫵�ǰ������ѹ��ջ��
			}
		}
	}
	while (!is_Empty(S)) {//��ջ�л��������
		Pop(S, ch);//���ε���
		cal[r++] = ch;//�����׺���ʽ
	}
	for (int i = 0; i < r; ++i) 
		putchar(cal[i]); //ѭ�������׺���ʽ
	putchar('\n');
	return 0;
}