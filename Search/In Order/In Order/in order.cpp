#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define ElemType int
#define MaxSize 114514
using namespace std;

typedef struct {//查找表的数据结构（顺序表）
	ElemType* elem;//动态数组基址
	int TableLen;//表的长度
}SSTable;

inline int Search_Seq(SSTable ST, ElemType key) {
	ST.elem[0] = key;//“哨兵”
	int i = ST.TableLen;
	for (; ST.elem[i] != key; --i);//从后往前找
	return i;//若查找成功，则返回元素下标；若查找失败，则返回0
}

inline void InitList(SSTable& ST) {//初始化
	ST.elem = (ElemType*)malloc(MaxSize * sizeof(ElemType));
	ST.TableLen = 0;
	return;
}

inline bool ListInsert(SSTable& ST, int i, ElemType e) {//在顺序表的第i个位置插入元素e
	if (i<1 || i>ST.TableLen + 1)return false;//判断i的范围是否有效
	if (ST.TableLen >= MaxSize)return false;//当前储存空间已满，不能插入
	for (int j = ST.TableLen; j > i; --j)
		ST.elem[j] = ST.elem[j - 1];//将第i个元素及之后的元素后移
	ST.elem[i] = e;//在位置i处放入e
	ST.TableLen++;//线性表长度加1
	return true;
}

inline bool ListDelete(SSTable& ST, int i, ElemType& e) {//删除第i个位置的元素
	if (i<1 || i>ST.TableLen)return false;//判断i的范围是否有效
	e = ST.elem[i];//将被删除的元素赋给e
	for (int j = i; j < ST.TableLen; ++j)
		ST.elem[j] = ST.elem[j + 1];//将第i个位置后的元素前移
	ST.TableLen--;//线性表长度减1
	return true;
}

inline int LocateElem(SSTable ST, ElemType e) {//按值查找（顺序查找）
	int i;
	for (int i = 1; i <= ST.TableLen; ++i)
		if (ST.elem[i] == e)return i;//若下标为i的元素值等于e，则返回该下标
	return 0;//查找失败返回0
}
//按位查找直接ST.elem[i]就是了，时间复杂度O(1)

int main() {

	return 0;
}