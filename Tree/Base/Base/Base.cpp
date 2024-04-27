#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

#define MaxSize 100
typedef struct TreeNode {
	int value;//结点中的数据元素
	bool isEmpty;//结点是否为空
}TreeNode;
TreeNode t[MaxSize];//静态顺序存储二叉树
int n;//记录结点总数

void TreeInit() {//初始化
	for (int i = 0; i < MaxSize; ++i)
		t[i].isEmpty = true;//将每个结点状态设为空
	return;
}

bool Have_LeftChild(int i) {//判断结点i是否有左孩子
	return (2 * i <= n && !t[2 * i].isEmpty) ? true : false;
}

bool Have_RightChild(int i) {//判断结点i是否有右孩子
	return (2 * i + 1 <= n && !t[2 * i + 1].isEmpty) ? true : false;
}

bool Is_Leaf(int i) {//判断结点i是否为叶子结点
	return i > (n / 2) ? true : false;
}

typedef struct Elemtype {//复合数据域
	int value;//只有一个int类型
}Elemtype;
typedef struct BiTNode {//二叉链表结点
	Elemtype data;//数据域
	struct BiTNode* lchild, * rchild;//左、右孩子指针
//	struct BiTNode* parent;//父节点指针（根据实际需要决定是否添加）
}BiTNode, * BiTree;

BiTree root = NULL;//定义一棵空树
void InitBiTree() {//初始化根结点
	root = (BiTree)malloc(sizeof(BiTNode));
	root->data = { 1 };
//	root->parent = NULL;
	root->lchild = NULL;
	root->rchild = NULL;
	return;
}
void InsertRLChild() {//插入新节点（根结点的左孩子）
	BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode));
	p->data = { 2 };
	p->lchild = NULL;
	p->rchild = NULL;
	root->lchild = p;
//	p->parent = root;
	return;
}

int main() {

	return 0;
}