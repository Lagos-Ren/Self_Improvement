#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>//输入输出流必备头文件
#define ull unsigned long long//用ull替换unsigned long long让代码更简洁
using namespace std;

typedef struct SNode{
	int len;//记录表长（栈内元素个数）
	ull data;//记录数据元素
	struct SNode* next;
}SNode,* SqStack;//单链表形式定义栈

inline void InitStack(SqStack& S) {//初始化栈
	S = (SNode*)malloc(sizeof(SNode));//分配头结点
	S->next = NULL;
	S->len = 0;//初始表长为0
	return;
}

inline bool StackEmpty(SqStack& S) {//判空
	return S->len == 0 ? true : false;//表长为0则为空栈
}

inline void Push(SqStack& S, ull x) {//入栈
	SNode* p = (SNode*)malloc(sizeof(SNode));//分配新结点
	if (p == NULL)return;//分配失败
	p->data = x;//记录新数据
	p->next = S->next;//将新节点p的后继指向栈顶元素的后继
	S->next = p;//栈顶元素的后继再指向p，完成插入
	S->len++;//表长+1
	return;
}

inline void Pop(SqStack& S) {//出栈
	if (StackEmpty(S))printf("Empty\n");//若表长为0则为空栈，按题意输出“Empty”
	else {
		SNode* p = S->next;//否则，用临时结点p指向栈顶元素
		S->next = p->next;//栈顶元素的后继指向其后继的后继
		free(p);//释放栈顶元素，完成出栈
		S->len--;//表长-1
	}
	return;
}

inline void Query(SqStack& S) {//询问栈顶元素
	if (StackEmpty(S))printf("Anguei!\n");//若表长为0则为空栈，按题意输出“Anguei!”
	else printf("%llu\n", S->next->data);//否则输出栈顶元素数据
	return;
}

int main() {
	int T,n;
	std::cin >> T;//std输入流
	string str;//记录操作字符串
	ull x;
	for (int i = 1; i <= T; ++i) {//T组数据
		std::cin >> n;
		SqStack S;//声明一个栈
		InitStack(S);
		for (int j = 1; j <= n; ++j) {//n次操作
			std::cin >> str;//std输入流，遇空格即停止，这一点比scanf好用
			if (str == "push") {//若为push，则进行入栈操作
				std::cin >> x;
				Push(S, x);
			}
			else if (str == "pop") {//若为pop，则进行出栈操作
				Pop(S);
			}
			else if (str == "query") {//若为query，则进行询问栈顶元素操作
				Query(S);
			}
			else if (str == "size") {//若为size，则输出表长
				printf("%d\n", S->len);
			}
		}
	}
	return 0;
}