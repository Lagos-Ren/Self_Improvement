#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>

int main() {
	char ch=getchar();
	printf("  %c\n", ch);
	printf(" %c%c%c\n", ch, ch, ch);
	for(int i=1;i<=5;++i)
		printf("%c", ch);
	putchar('\n');
	return 0;
}