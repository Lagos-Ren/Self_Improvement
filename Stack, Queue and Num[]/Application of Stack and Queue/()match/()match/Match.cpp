#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define MaxSize 100
typedef struct{
	char data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack& S) {
	S.top = -1;
	return;
}

bool StackEmpty(SqStack& S) {
	return S.top == -1 ? true : false;
}

bool Push(SqStack& S, char ch) {
	if (S.top == MaxSize - 1)return false;
	S.data[++S.top] = ch;
	return true;
}

bool Pop(SqStack& S, char& ch) {
	if (StackEmpty(S))return false;
	ch = S.data[S.top--];
	return true;
}

bool bracketCheck(char str[], int len) {
	SqStack S;
	InitStack(S);
	char ch1,ch2;
	for (int i = 0; i < len; ++i) {
		ch1 = str[i];
		if (ch1 == '(' || ch1 == '[' || ch1 == '{') {
			Push(S, ch1);
			continue;
		}
		else Pop(S, ch2);
		if (ch1 == ')' && ch2 != '(')return false;
		if (ch1 == ']' && ch2 != '[')return false;
		if (ch1 == '}' && ch2 != '{')return false;
	}
	return StackEmpty(S);
}

int main() {
	char s[MaxSize];
	scanf("%s", s);
	if(bracketCheck(s,strlen(s)))printf("OK\n");
	else printf("ERROR!\n");
	return 0;
}