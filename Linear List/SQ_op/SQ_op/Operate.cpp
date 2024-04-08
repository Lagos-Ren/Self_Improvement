#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#define InitSize 10
#define Addlen 5
using namespace std;

typedef struct {
	int* data;
	int MaxSize;
	int length;
}SeqList;

void InitList(SeqList& L);
void IncreaseSize(SeqList& L, int len);
void PrintList(SeqList& L);

bool ListInsert(SeqList& L, int i, int e) {//�������
	if (i<1 || i>L.length + 1)return false;
	if (L.length >= L.MaxSize) {
//		IncreaseSize(L, Addlen);
		return false;
	}
	for (int j = L.length; j >= i; --j) {//��i֮���Ԫ�غ���һλ
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;//����Ԫ��
	L.length++;//�ܳ��ȼ�һ
	return true;
}

bool ListDelete(SeqList& L, int i, int& e) {//ɾ������
	if (i<1 || i>L.length + 1)return false;
	e = L.data[i - 1];//����ɾ����Ԫ�ش���ȥ
	for (int j = i; j < L.length; ++j) {
		L.data[j - 1] = L.data[j];//����iλ֮���Ԫ������ǰ��
	}
	L.length--;//�ܳ��ȼ�һ
	return true;
}

int GetElem(SeqList& L, int i){//��λ���ң��޷��ж�i�ĺϷ��ԣ������������������ж�
	return L.data[i - 1];
}

int LocateElem(SeqList& L, int e) {//��ֵ���ң��޷������ظ����ֵ�Ԫ�ص�����λ��
	int i = 0;
	for (; i < L.length; ++i) {
		if (L.data[i] == e)return i + 1;
	}return 0;
}

int main() {
	SeqList L;
	InitList(L);
	int i;
	for (i = 0; i < L.MaxSize; ++i) {
		L.data[i] = i;
	}L.length = L.MaxSize;
	PrintList(L);
	IncreaseSize(L, Addlen);
	if (!ListInsert(L, 3, 114514)) {
		printf("Error!\n");
	}else PrintList(L);
	int e = 0;
	if (!ListDelete(L, 4, e)) {
		printf("Error!\n");
	}else {
		printf("��ɾ����Ԫ���ǵ�4λ��%d\n",e);
		PrintList(L);
	}
	printf("��5��Ԫ����%d\n", GetElem(L, 5));
	printf("114514�ǵ�%d��Ԫ��\n", LocateElem(L, 114514));
	return 0;
}

void InitList(SeqList& L) {
	L.data = (int*)malloc(InitSize * sizeof(int));
	L.length = 0;
	L.MaxSize = InitSize;
	return;
}

void IncreaseSize(SeqList& L, int len) {
	int* p = L.data;
	L.data = (int*)malloc((L.MaxSize + len) * sizeof(int));
	for (int i = 0; i < L.length; ++i) {
		L.data[i] = p[i];
	}
	L.MaxSize += len;
	free(p);
	return;
}

void PrintList(SeqList& L) {
	printf("List L:");
	for (int i = 0; i < L.length; ++i) {
		printf("%d ", L.data[i]);
	}printf("\n");
	printf("L.length=%d, L.MaxSize=%d\n", L.length, L.MaxSize);
	return;
}