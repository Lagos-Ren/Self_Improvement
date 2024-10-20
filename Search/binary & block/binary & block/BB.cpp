#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define ElemType int
#define MaxSize 114514
using namespace std;

typedef struct {//���ұ�����ݽṹ��˳���
	ElemType* elem;//��̬�����ַ
	int TableLen;//��ĳ���
}SSTable;

inline int Search_Seq(SSTable L, ElemType key) {//��������
	int l = 1, r = L.TableLen, mid;//lΪleft��rΪright
	while (l <= r) {
		mid = (l + r) / 2;//ȡ�м�λ��
		if (L.elem[mid] == key)return mid;//���ҳɹ��򷵻�����λ��
		else if (L.elem[mid] > key)r = mid - 1;//��ǰ�벿�ּ�������
		else l = mid + 1;//�Ӻ�벿�ּ�������
	}
	return -1;//����ʧ�ܣ�����-1
}

inline int Search__Seq(SSTable L, ElemType key) {//��������
	int l = 1, r = L.TableLen, mid;//lΪleft��rΪright
	while (l <= r) {
		mid = (l + r) / 2;//ȡ�м�λ��
		if (L.elem[mid] == key)return mid;//���ҳɹ��򷵻�����λ��
		else if (L.elem[mid] > key)l = mid + 1;//�Ӻ�벿�ּ�������
		else r = mid - 1;//��ǰ�벿�ּ�������
	}
	return -1;//����ʧ�ܣ�����-1
}

int main() {

	return 0;
}