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

typedef struct {//��̬����ʵ��
	char* ch;//����������洢����chָ�򴮵Ļ���ַ
	int length;
}HString;//���ѷ���洢��

typedef struct LNode {//������ʽ�洢
//	char ch;//ÿ������һ���ַ���ռ��1B���洢�ܶȵͣ���������
	char ch[4];//���������ÿ���������ַ�����ߴ洢�ܶ�
	struct LNode* next;//ÿ������һ��ָ�룬ռ��4B
}LNode, * String;

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

void ClearString(HString& S) {//��գ���̬����Ͷ�̬�����߼���ͬ��
	S.length = 0;
	return;
}

void DestoryString(HString& S) {//���٣����ѷ��䣩
	free(S.ch);
	S.ch = NULL;//�������е��߼��붯̬����Ĵ���ʼ���߼���ͬ
	S.length = 0;
	return;
}

void StrAssign(SString& S, char c[]) {//��ֵ
	InitString(S);//��ʼ����S��ֹ���ڲ������������ݡ�
	int len = strlen(c)-1;
	//��Ϊ�����ַ����鴫�Σ���Ҫ���䳤��-1���ų������±�Ϊ0�����ݸ���
	if (len == 0)return;//���������ǿմ������������
	else S.length = len;//���򽫴�������Ϊlen
	for (int i = 1; i <= len; ++i)
		S.ch[i] = c[i];//��λ�����ַ���
	return;
}
/*
void StrAssign(HString& S, char *chars) {
	DestoryString(S);
	int len = strlen(chars);
	if (len == 0)return;
	else S.length = len;
	S.ch = (char*)malloc(len * sizeof(char));
	for (int i = 0; i < len; ++i)
		S.ch[i] = chars[i];
	return;
}
*/
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

int main() {
	SString S;
	InitString(S);
	char c1[] = " wdnmd";
	StrAssign(S,c1);
//	printf("%s %d\n", c1, strlen(c1));
	for (int i = 1; i <= S.length; ++i) {
		printf("%c", S.ch[i]);
	}
	printf("\n");
	SString T;
	char c2[] = " dn";
	StrAssign(T, c2);
//	printf("%s %d\n", c2, strlen(c2));
	for (int i = 1; i <= T.length; ++i) {
		printf("%c", T.ch[i]);
	}
	printf("\n");
	printf("%d\n", Index(S, T));
	return 0;
}