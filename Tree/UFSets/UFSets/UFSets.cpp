#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
#define SIZE 100
int UFSets[SIZE];//集合元素数组（双亲指针数组）

void Init(int S[]) {//初始化
	memset(S, -1, sizeof(S));
	//数组各元素初值置-1，表示每个单元自成集合，这个memset等价于下面的写法
	/*
	for (int i = 0; i < SIZE; ++i)
		S[i] = -1;
	*/
	return;
}

int Find(int S[], int x) {//“查”操作，找到x所属集合（返回x所属树的根结点）
	while (S[x] >= 0)//循环查找x的根
		x = S[x];
	return x;//根的S[]小于0
}

void Union(int S[], int Root1, int Root2) {
	//“并”操作，将两个集合合并为一个
	if (Root1 != Root2)S[Root2] = Root1;
	//若Root1和Root2是两个不同的集合，则将根Root2连在另一根Root1下面
	return;
}

void Union_(int S[], int Root1, int Root2) {//改进后的“并”操作
	if (Root1 == Root2)return;//同一集合无需合并
	if (S[Root2] > S[Root1]) {//若Root2结点数更少
		S[Root1] += S[Root2];//累加集合树的结点总数
		S[Root2] = Root1;//小树合并到大树
	}
	else {//Root1结点数更少
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	}
	return;
}

int Find_(int S[], int x) {//改进后的“查”操作
	int root = x;
	while (S[root] >= 0)root = S[root];//循环找到根
	for (int t; x != root; t = S[x], S[x] = root, x = t);//路径压缩
	/*for循环等价于下面的while循环
	while (x != root) {
		int t = S[x];
		S[x] = root;
		x = t;
	}
	*/
	return root;//返回根
}

int main() {

	return 0;
}
