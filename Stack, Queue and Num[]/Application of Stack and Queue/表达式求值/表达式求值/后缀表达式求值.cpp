#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define MaxSize 100
int num[MaxSize] = { 0 }, top = -1;
//��̬����������ջ����ʼ��ջ��ָ��Ϊ-1

bool is_num(char ch) {//�ж��ַ��Ƿ�Ϊ�����ַ�
	return ('0' <= ch && ch <= '9') ? true : false;
}

int main() {
	int len = 0;
	char str[MaxSize],ch;//str�ַ������¼��׺���ʽ
	while (ch = getchar()) {//��λ����
		if (ch == '\n')break;//�������з����������
		str[len++] = ch;//���򽫶������ַ������ַ�����
	}
	int a;//��ʱ����
	for (int i = 0; i < len; ++i) {//��λɨ���׺���ʽ
		if (str[i] == ' ')continue;//��Ϊ�ո�������
		if (is_num(str[i])) {//����ǰλΪ����
			a = 0;
			for (; i < len; ++i) {//ѭ�����ɨ�裬ֱ����ǰλ��Ϊ����Ϊֹ
				if (is_num(str[i]))a = a * 10 + (int)(str[i] - '0');//�����������ѭ���ۼӽ��м�¼
				else break;//��������������ѭ��
			}
			i--;//��λ
			num[++top] = a;//��������ѹ��ջ��
			continue;
		}
		else {//����ǰλ��������
			if (str[i] == '+') {//��Ϊ+��
				a = num[top--];//����ջ��Ԫ�أ���a��¼
				num[top] += a;//���µ�ջ��Ԫ����ֵ����a����ɼӷ�����
			}
			else if (str[i] == '-') {//��Ϊ-��
				a = num[top--];//����ջ��Ԫ�أ���a��¼
				num[top] -= a;//���µ�ջ��Ԫ����ֵ��ȥa����ɼ�������
			}
			else if (str[i] == '*') {//�˳�����Ӽ����߼�����
				a = num[top--];
				num[top] *= a;
			}
			else if (str[i] == '/') {
				a = num[top--];
				num[top] /= a;
			}
		}
	}
	printf("%d\n", num[top]);//���ջ��ʣ���Ԫ�ؼ��Ǻ�׺���ʽ��ֵ
	return 0;
}