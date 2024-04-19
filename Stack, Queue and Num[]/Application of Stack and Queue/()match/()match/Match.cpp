#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define MaxSize 100
typedef struct{
	char data[MaxSize];//��̬����ʵ��˳��ջ
	int top;//ջ��ָ��
}SqStack;

void InitStack(SqStack& S) {//��ʼ��ջ
	S.top = -1;//ջ��ָ��ָ��-1
	return;
}

bool StackEmpty(SqStack& S) {//�ж�ջ�Ƿ�Ϊ�գ���ջ��ָ���Ƿ�ָ��-1
	return S.top == -1 ? true : false;
}

bool Push(SqStack& S, char ch) {//��ջ
	if (S.top == MaxSize - 1)return false;//��ջ���򱨴�
	S.data[++S.top] = ch;//ջ��ָ����+1��������Ԫ����ջ
	return true;
}

bool Pop(SqStack& S, char& ch) {//��ջ������ch����ջ��Ԫ��
	if (StackEmpty(S))return false;//ջ�ձ���
	ch = S.data[S.top--];//�ȼ�¼ջ��Ԫ�أ�����ջ��ָ��-1
	return true;
}

bool bracketCheck(char str[], int len) {//����ַ���
	SqStack S;//����һ��ջ
	InitStack(S);//��ʼ��ջS
	char ch1,ch2;//��ʱ����
	for (int i = 0; i < len; ++i) {
		ch1 = str[i];//��λ��ȡ�ַ���
		if (ch1 == '(' || ch1 == '[' || ch1 == '{') {//��Ϊ����������ջ
			if (!Push(S, ch1))return false;//��ջʧ�ܱ���
			continue;//��ջ�ɹ�����������ַ�������һλ
		}
		else if (!Pop(S, ch2))return false;//�����ջ�����жϳ�ջ�Ƿ�ɹ�
		if (ch1 == ')' && ch2 != '(')return false;//С����ƥ��
		if (ch1 == ']' && ch2 != '[')return false;//������ƥ��
		if (ch1 == '}' && ch2 != '{')return false;//������ƥ��
	}
	return StackEmpty(S);//����ж�ջ�Ƿ�Ϊ�գ���Ϊ���򷵻�true������false
}

int main() {
	char s[MaxSize];
	scanf("%s", s);//�����ַ���
	if(bracketCheck(s,strlen(s)))printf("OK\n");//��ƥ��ͨ�����OK
	else printf("ERROR\n");//�������ERROR
	return 0;
}