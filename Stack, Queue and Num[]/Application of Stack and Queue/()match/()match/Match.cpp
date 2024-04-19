#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define MaxSize 100
typedef struct{
	char data[MaxSize];//静态数组实现顺序栈
	int top;//栈顶指针
}SqStack;

void InitStack(SqStack& S) {//初始化栈
	S.top = -1;//栈顶指针指向-1
	return;
}

bool StackEmpty(SqStack& S) {//判断栈是否为空，看栈顶指针是否指向-1
	return S.top == -1 ? true : false;
}

bool Push(SqStack& S, char ch) {//入栈
	if (S.top == MaxSize - 1)return false;//若栈满则报错
	S.data[++S.top] = ch;//栈顶指针先+1，再让新元素入栈
	return true;
}

bool Pop(SqStack& S, char& ch) {//出栈，并用ch返回栈顶元素
	if (StackEmpty(S))return false;//栈空报错
	ch = S.data[S.top--];//先记录栈顶元素，再让栈顶指针-1
	return true;
}

bool bracketCheck(char str[], int len) {//检查字符串
	SqStack S;//声明一个栈
	InitStack(S);//初始化栈S
	char ch1,ch2;//临时变量
	for (int i = 0; i < len; ++i) {
		ch1 = str[i];//按位读取字符串
		if (ch1 == '(' || ch1 == '[' || ch1 == '{') {//若为左括号则入栈
			if (!Push(S, ch1))return false;//入栈失败报错
			continue;//入栈成功则继续处理字符串的下一位
		}
		else if (!Pop(S, ch2))return false;//否则出栈，且判断出栈是否成功
		if (ch1 == ')' && ch2 != '(')return false;//小括号匹配
		if (ch1 == ']' && ch2 != '[')return false;//中括号匹配
		if (ch1 == '}' && ch2 != '{')return false;//大括号匹配
	}
	return StackEmpty(S);//最后判断栈是否为空，若为空则返回true，否则false
}

int main() {
	char s[MaxSize];
	scanf("%s", s);//读入字符串
	if(bracketCheck(s,strlen(s)))printf("OK\n");//若匹配通过输出OK
	else printf("ERROR\n");//否则输出ERROR
	return 0;
}