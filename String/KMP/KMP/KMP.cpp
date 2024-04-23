#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

#define MaxLen 259//Ԥ������󴮳����¾�����ָ��259
typedef struct {//��̬����洢
	char ch[MaxLen];//�ַ����鴢�洮
	int length;//����
}SString;
int nex[MaxLen] = { 0 };
/*
void InitString(SString& S) {//��ʼ��
	S.length = 0;
	return;
}

bool StrEmpty(SString S) {//�п�
	return S.length == 0 ? true : false;
}

int StrLength(SString S) {//�󴮳�
	return S.length;
}

void StrAssign(SString& S, char c[]) {//��ֵ
	InitString(S);//��ʼ����S��ֹ���ڲ������������ݡ�
	int len = strlen(c) - 1;
	//��Ϊ�����ַ����鴫�Σ���Ҫ���䳤��-1���ų������±�Ϊ0�����ݸ���
	if (len == 0)return;//���������ǿմ������������
	else S.length = len;//���򽫴�������Ϊlen
	for (int i = 1; i <= len; ++i)
		S.ch[i] = c[i];//��λ�����ַ���
	return;
}

void StrCopy(SString& S, SString& T) {//����
	S.length = T.length;
	for (int i = 1; i <= T.length; ++i)
		S.ch[i] = T.ch[i];
	return;
}

void Contact(SString& S, char T1[], char T2[]) {//�����ӣ���S����T1,T2ƴ�ӳɵ��´�
	int len1 = strlen(T1) - 1, len2 = strlen(T2) - 1, i;
	//len1��ʾT1������len2��ʾT2������i��ʾ���Ӵ������±�
	for (i = 1; i <= len1; ++i)
		S.ch[i] = T1[i];//�ȸ���T1��
	for (int j = 1; j <= len2; ++i, ++j)
		S.ch[i] = T2[j];//���������T2��
	S.length = len1 + len2;//�´��ĳ��ȵ����������Ⱥ�
	return;
}

bool SubString(SString& Sub, SString S, int pos, int len) {
	//����S���У���posλ�ÿ�ʼ������Ϊlen���Ӵ�������Sub����
	if (pos + len - 1 > S.length)return false;//����Ӵ�λ�úͳ��ȷǷ�ֱ�ӷ���false
	for (int i = pos; i < pos + len; ++i)//��pos����ʼ����pos+len-1������ 
		Sub.ch[i - pos + 1] = S.ch[i];
	Sub.length = len;//�Ӵ����Ⱦ���len
	return true;
}

int StrCompare(SString S, SString T) {//�Ƚϴ���С
	//��S����T��������ֵ��0����S��=T��������ֵ=0����S����T��������ֵ��0
	for (int i = 1; i <= S.length && i <= T.length; ++i)
		if (S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	return S.length - T.length;//���Ĵ�ֵ����
}

int Index(SString S, SString T) {//��ѯ�Ӵ�T������S�е�λ��
	SString Sub;//��ʱ�Ӵ�Sub
	for (int i = 1; i <= S.length - T.length + 1; ++i) {
		SubString(Sub, S, i, T.length);//��λ��1��ʼ���ң�����Sub��ʱ����Ӵ�
		if (StrCompare(Sub, T) != 0)continue;//�Ƚ�Sub��T�������ͬ�����ѭ��
		else return i;//���򷵻�i����T��S�е�һ�γ��ֵ�λ��
	}
	return 0;//��δ�ҵ��򷵻�0
}
*/
int Index(SString S, SString T) {//����ģʽƥ���㷨
	int i = 1, j = 1;
	for (; i <= S.length && j <= T.length; ++i, ++j) {
		if (S.ch[i] == T.ch[j])continue;
		else {
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > T.length)return i - T.length;
	else return 0;
}//�ʱ�临�Ӷ�ΪO(nm)

int Index_KMP(SString S, SString T) {//KMP�㷨
	int i = 1, j = 1;
	for (; i <= S.length && j <= T.length; ++i, ++j) {
		if (j == 0 || S.ch[i] == T.ch[j])continue;
		//��jΪ0��ǰλƥ��ɹ��������ƥ��
		else j = nex[j];//���������ƶ�ģʽ��
	}
	if (j > T.length)return i - T.length;//ƥ��ɹ�
	else return 0;//ƥ��ʧ�ܷ���0
}//�ʱ�临�Ӷ�O(n+m)

void Get_Next(SString S) {//��ȡnext����
	nex[1] = 0, nex[2] = 1;
	for (int i = 1, j = 0; i < S.length;) {
		//i��¼next�����±꣬j��¼ģʽ��ǰ׺�±�
		if (j == 0 || S.ch[i] == S.ch[j])nex[++i] = ++j;
		//����iλ�͵�jλƥ�䣬��������ƥ��ʱ��ģʽ���ĵ�iλ��ƥ��Ļ���ģʽ��ֱ���ƶ�����jλ
		//����һֱƥ����ȥ����nextֵ�ļ���ʵ���ϵȼ���next[j+1]=next[j]+1
		else j = nex[j];//������j=next[j]������nextֵ�����j�ص�0
	}
/*	//��������д������
	int i = 1, j = 0;
	nex[1] = 0;
	while (i < S.length) {
		if (j == 0 || S.ch[i] == S.ch[j]) {
			++i, ++j;
			nex[i] = j;//��pi=pj����next[j+1]=next[j]+1
		}
		else j = nex[j];//������j=next[j]��ѭ������
	}
*/	return;
}

int main() {


	return 0;
}