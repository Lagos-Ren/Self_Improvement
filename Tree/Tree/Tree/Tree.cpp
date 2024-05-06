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

int main() {


	return 0;
}