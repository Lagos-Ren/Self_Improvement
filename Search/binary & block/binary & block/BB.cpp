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

inline int Search_Seq(SSTable L, ElemType key) {//升序排列
	int l = 1, r = L.TableLen, mid;//l为left，r为right
	while (l <= r) {
		mid = (l + r) / 2;//取中间位置
		if (L.elem[mid] == key)return mid;//查找成功则返回所在位置
		else if (L.elem[mid] > key)r = mid - 1;//从前半部分继续查找
		else l = mid + 1;//从后半部分继续查找
	}
	return -1;//查找失败，返回-1
}

inline int Search__Seq(SSTable L, ElemType key) {//降序排列
	int l = 1, r = L.TableLen, mid;//l为left，r为right
	while (l <= r) {
		mid = (l + r) / 2;//取中间位置
		if (L.elem[mid] == key)return mid;//查找成功则返回所在位置
		else if (L.elem[mid] > key)l = mid + 1;//从后半部分继续查找
		else r = mid - 1;//从前半部分继续查找
	}
	return -1;//查找失败，返回-1
}

int main() {

	return 0;
}