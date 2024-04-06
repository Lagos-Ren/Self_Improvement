#include<cstdio>
#include<cstdlib>
#define InitSize 10
using namespace std;

typedef struct {
	int* data;
	int MaxSize;
	int length;
}SeqList;

void InitList(SeqList& L) {//初始化，&表示引用
	L.data = (int*)malloc(InitSize * sizeof(int));
	//malloc函数申请一整片连续的存储空间，用sizeof(数据类型)初始化，可以乘上一个初始值
	//之后malloc会返回一个指针，将这个指针类型转化成和被初始化数组相同的类型，再赋值给data
	//最终data指向L.data[0]
	L.length = 0;
	L.MaxSize = InitSize;
	return;
}

void IncreaseSize(SeqList& L, int len) {
	int* p=L.data;
	L.data = (int*)malloc((L.MaxSize + len) * sizeof(int));
	//malloc分配当前存储上线再加上len的存储空间
	//data指向新分配的这一片空间
	for (int i = 0; i < L.length; ++i) {
		L.data[i] = p[i];//将以前的数据转移过来
	}
	L.MaxSize += len;
	free(p);
	return;
}//realloc函数也可实现，但不推荐初学者使用

int main() {
	SeqList L;
	InitList(L);
	IncreaseSize(L, 5);
	return 0;
}