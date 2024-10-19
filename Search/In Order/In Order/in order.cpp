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

inline int Search_Seq(SSTable ST, ElemType key) {
	ST.elem[0] = key;//���ڱ���
	int i = ST.TableLen;
	for (; ST.elem[i] != key; --i);//�Ӻ���ǰ��
	return i;//�����ҳɹ����򷵻�Ԫ���±ꣻ������ʧ�ܣ��򷵻�0
}

inline void InitList(SSTable& ST) {//��ʼ��
	ST.elem = (ElemType*)malloc(MaxSize * sizeof(ElemType));
	ST.TableLen = 0;
	return;
}

inline bool ListInsert(SSTable& ST, int i, ElemType e) {//��˳���ĵ�i��λ�ò���Ԫ��e
	if (i<1 || i>ST.TableLen + 1)return false;//�ж�i�ķ�Χ�Ƿ���Ч
	if (ST.TableLen >= MaxSize)return false;//��ǰ����ռ����������ܲ���
	for (int j = ST.TableLen; j > i; --j)
		ST.elem[j] = ST.elem[j - 1];//����i��Ԫ�ؼ�֮���Ԫ�غ���
	ST.elem[i] = e;//��λ��i������e
	ST.TableLen++;//���Ա��ȼ�1
	return true;
}

inline bool ListDelete(SSTable& ST, int i, ElemType& e) {//ɾ����i��λ�õ�Ԫ��
	if (i<1 || i>ST.TableLen)return false;//�ж�i�ķ�Χ�Ƿ���Ч
	e = ST.elem[i];//����ɾ����Ԫ�ظ���e
	for (int j = i; j < ST.TableLen; ++j)
		ST.elem[j] = ST.elem[j + 1];//����i��λ�ú��Ԫ��ǰ��
	ST.TableLen--;//���Ա��ȼ�1
	return true;
}

inline int LocateElem(SSTable ST, ElemType e) {//��ֵ���ң�˳����ң�
	int i;
	for (int i = 1; i <= ST.TableLen; ++i)
		if (ST.elem[i] == e)return i;//���±�Ϊi��Ԫ��ֵ����e���򷵻ظ��±�
	return 0;//����ʧ�ܷ���0
}
//��λ����ֱ��ST.elem[i]�����ˣ�ʱ�临�Ӷ�O(1)

int main() {

	return 0;
}