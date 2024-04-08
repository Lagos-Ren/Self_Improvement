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

bool ListInsert(SeqList& L, int i, int e) {//插入操作
	if (i<1 || i>L.length + 1)return false;
	if (L.length >= L.MaxSize) {
//		IncreaseSize(L, Addlen);
		return false;
	}
	for (int j = L.length; j >= i; --j) {//将i之后的元素后移一位
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;//插入元素
	L.length++;//总长度加一
	return true;
}

bool ListDelete(SeqList& L, int i, int& e) {//删除操作
	if (i<1 || i>L.length + 1)return false;
	e = L.data[i - 1];//将被删除的元素传回去
	for (int j = i; j < L.length; ++j) {
		L.data[j - 1] = L.data[j];//将第i位之后的元素依次前移
	}
	L.length--;//总长度减一
	return true;
}

int GetElem(SeqList& L, int i){//按位查找，无法判断i的合法性，可在主函数中先行判断
	return L.data[i - 1];
}

int LocateElem(SeqList& L, int e) {//按值查找，无法查找重复出现的元素的所有位置
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
		printf("被删除的元素是第4位的%d\n",e);
		PrintList(L);
	}
	printf("第5个元素是%d\n", GetElem(L, 5));
	printf("114514是第%d个元素\n", LocateElem(L, 114514));
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