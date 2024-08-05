#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

typedef struct LinkNode {
	char ch;
	struct LinkNode* next;
}LinkNode, * LinkList;
LinkList L;
int num[305];

inline void Init() {
	memset(num, 0, sizeof(num));
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode*));
	p->ch = '\0';
	p->next = NULL;
	L = p;
	return;
}

inline bool Judge(char ch) {
	return ch == ' ' ? false : true;
}

inline void Opt() {
	char ch;
	int ct = 0, tot = 0;
	for (LinkNode* p = L->next; p != NULL; p = p->next) {
		ch = p->ch;
		if (!Judge(ch)) {
			if (tot == 0)continue;
			else {
				num[++ct] = tot, tot = 0;
				continue;
			}
		}
		else tot++;
	}
	if (tot != 0)num[++ct] = tot;
	return;
}

inline void Print() {
	for (int i = 1;; ++i) {
		if (!num[i + 1]) {
			cout << num[i] << endl;
			break;
		}
		else cout << num[i] << ",";
	}
	return;
}

int main() {
//	freopen("std.in", "r", stdin);
	Init();
	char ch;
	LinkNode* s, * tail;
	tail = L;
	while (scanf("%c", &ch) != EOF) {
		s = (LinkNode*)malloc(sizeof(LinkNode*));
		s->ch = ch;
		tail->next = s;
		tail = s;
	}
	tail->next = NULL;
	Opt();
	Print();
	return 0;
}