#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>//����malloc����
#define MAX_SIZE 10

typedef struct {
	int data[MAX_SIZE];
	int length;
}Sqlist;

void InitList(Sqlist *b) {
	for (int i = 0; i < MAX_SIZE; ++i)
		b->data[i] = 0;
	b->length = 0;
	return;
}

int main() {
	Sqlist L;
	Sqlist* a = (Sqlist*)malloc(sizeof(Sqlist));//�����ڴ��ָ��a
	//if (a == NULL) {
	//	printf("Memory allocation failed.\n");
	//	return 1;
	//}
	InitList(a);
	free(a);
	return 0;
}