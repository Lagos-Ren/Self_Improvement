#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define MaxSize 100
typedef struct LNode {
	char data;
	struct LNode* next;
}LNode,*SqStack;//单链表方式定义顺序栈

void InitStack(SqStack& S) {//初始化栈
	S = (LNode*)malloc(sizeof(LNode));
	if (S == NULL)return;
	S->next = NULL;
	return;
}

bool is_Empty(SqStack& S) {//判断栈是否为空
	return S->next == NULL ? true : false;
}

bool Push(SqStack& S, char ch) {//新元素入栈
	LNode* p = (LNode*)malloc(sizeof(LNode));
	if (p == NULL)return false;
	p->data = ch;
	p->next = S->next;
	S->next = p;
	return true;
}

bool Pop(SqStack& S, char& ch) {//栈顶元素出栈，并用ch返回其值
	if (is_Empty(S))return false;
	LNode* p = S->next;
	ch = p->data;
	S->next = p->next;
	free(p);
	return true;
}

bool Query(SqStack& S, char& ch) {//仅查询栈顶元素，用ch返回
	if (is_Empty(S))return false;
	ch = S->next->data;
	return true;
}

bool is_Op(char ch) {//判断ch是否为操作符
	if (ch == '+')return true;
	if (ch == '-')return true;
	if (ch == '/')return true;
	if (ch == '*')return true;
	if (ch == '(')return true;
	if (ch == ')')return true;
	return false;
}

bool is_Prim(char a, char b) {//判断操作符的优先级，若a的优先级高于b则返回true
	if (a == '(' || a == ')')return true;
	if (a == '*' || a == '/') {
		if (b == '+' || b == '-' || b == '*' || b == '/')return true;
	}
	if (a == '+' || a == '-') {
		if (b == '+' || b == '-')return true;
	}
	return false;
}

int main() {
	int len = 0, r = 0;//len记录中缀表达式长度，r记录后缀表达式长度
	char str[MaxSize], ch;//str字符数组记录中缀表达式
	char cal[MaxSize];//cal字符数组记录后缀表达式
	SqStack S;//声明一个栈
	InitStack(S);//初始化栈
	while (ch = getchar()) {//按位读入中缀表达式
		if (ch == '\n')break;//读到换行符则结束输入
		str[len++] = ch;//否则将读到的字符存入字符数组
	}
	for (int i = 0; i < len; ++i) {//按位扫描中缀表达式
		if (!is_Op(str[i])) {//若当前位为操作数
			cal[r++] = str[i];//直接将操作数放入后缀表达式
			continue;
		}
		else {//否则当前位为操作符
			if (str[i] == '(') {//若为左括号则直接压入栈中
				Push(S, str[i]);
				continue;
			}
			else if (str[i] == ')') {//若为右括号
				while (!is_Empty(S)) {//则让栈中操作符依次出栈
					Pop(S, ch);
					if (ch == '(')break;//直到左括号为止
					cal[r++] = ch;//将出栈的操作符放入后缀表达式
				}
				continue;
			}
			else {//加减乘除运算符可以用同一套逻辑
				if (is_Empty(S)) {//若栈空则直接压入
					Push(S, str[i]);
					continue;
				}
				if (Query(S, ch)) {//否则需要将当前运算符与栈中运算符对比
					while (!is_Empty(S)) {
						//若栈非空，则需要把栈中优先级高于或等于当前运算符的所有运算符弹出
						//并加入到后缀表达式中
						Query(S, ch);//更新ch为栈顶运算符
						if (!is_Prim(ch, str[i]))break;//若栈顶运算符优先级更低则停止出栈
						Pop(S, ch);//出栈
						if (ch == '(')break;//若为左括号则直接跳出循环，防止其进入后缀表达式
						cal[r++] = ch;//将栈顶的运算符加入后缀表达式
					}
				}
				Push(S, str[i]);//最后将当前操作符压入栈中
			}
		}
	}
	while (!is_Empty(S)) {//若栈中还有运算符
		Pop(S, ch);//依次弹出
		cal[r++] = ch;//加入后缀表达式
	}
	for (int i = 0; i < r; ++i) 
		putchar(cal[i]); //循环输出后缀表达式
	putchar('\n');
	return 0;
}