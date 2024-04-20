#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define MaxSize 100
int num[MaxSize] = { 0 }, top = -1;

bool is_num(char ch) {
	return ('0' <= ch && ch <= '9') ? true : false;
}

int main() {
	int len = 0;
	char str[MaxSize],ch;
	while (ch = getchar()) {
		if (ch == '\n')break;
		str[len++] = ch;
	}
	int a, b;
//	printf("len=%d\n", len);
	for (int i = 0; i < len; ++i) {
//		printf("i=%d, str[i]=%c\n", i, str[i]);
		if (str[i] == ' ')continue;
		if (is_num(str[i])) {
			a = 0;
			int j;
			for (j = i; j < len; ++j) {
//				printf("j=%d\n", j);
				if (is_num(str[j]))a = a * 10 + (int)(str[j] - '0');
				else break;
			}
			i = j - 1;
			num[++top] = a;
//			printf("top=%d, i=%d, a=%d\n",top, i, a);
			continue;
		}
		else {
			if (str[i] == '+') {
				a = num[top--];
				num[top] += a;
			}
			else if (str[i] == '-') {
				a = num[top--];
				num[top] -= a;
			}
			else if (str[i] == '*') {
				a = num[top--];
				num[top] *= a;
			}
			else if (str[i] == '/') {
				a = num[top--];
				num[top] /= a;
			}
		}
	}
	printf("%d\n", num[top]);
	return 0;
}