#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

#define MAX_TREE_SIZE 100
typedef struct ElemType {
	int value;
}ElemType;//预处理

typedef struct {
	ElemType data;
	int parent;//双亲位置域
}PTNode;
typedef struct {//树的类型定义
	PTNode nodes[MAX_TREE_SIZE];//双亲表示
	int n;//结点数
}PTree;

struct CTNode {//单链表（B站弹幕说是邻接表）
	int child;//孩子节点在数组中的位置
	struct CTNode* next;//下一个孩子
};
typedef struct {
	ElemType data;
	struct CTNode* firstChild;//第一个孩子
}CTBox;
typedef struct {
	CTBox nodes[MAX_TREE_SIZE];//孩子表示法
	int n, r;//结点数和根的位置
}CTree;

typedef struct CSNode {//孩子兄弟表示法
	ElemType data;//数据域
	struct CSNode* firstchild, * nextsibling;//第一个孩子和右兄弟指针
}CSNode, * CSTree;

void Visit(CSNode* T) {
	cout << T->data.value << " ";
	return;
}

void PreOrder(CSTree T) {//先根遍历（使用孩子兄弟表示法）
	if (T != NULL) {
		Visit(T);//访问根结点
		CSTree C = T->firstchild;//C记录当前树根结点的第一个孩子
		do {//首先对以C为根的子树进行先根遍历
			PreOrder(C);
			C = C->nextsibling;//再依次对C的右兄弟为根的子树进行先根遍历
		} while (C != NULL);//当C还有其他右兄弟时循环继续
	}
	return;
}

void PostOrder(CSTree T) {//后根遍历
	if (T != NULL) {
		CSTree C = T->firstchild;
		do {
			PostOrder(C);//对以C为根的子树后根遍历
			C = C->nextsibling;//依次访问C的右兄弟结点
		} while (C != NULL);
		Visit(T);//最后访问根结点
	}
	return;
}


int main() {


	return 0;
}