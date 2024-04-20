#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define MaxSize 100
int num[MaxSize] = { 0 }, top = -1;
//静态数组存放数据栈，初始化栈顶指针为-1

bool is_num(char ch) {//判断字符是否为数字字符
	return ('0' <= ch && ch <= '9') ? true : false;
}

int main() {
	int len = 0;
	char str[MaxSize],ch;//str字符数组记录后缀表达式
	while (ch = getchar()) {//按位读入
		if (ch == '\n')break;//读到换行符则结束输入
		str[len++] = ch;//否则将读到的字符存入字符数组
	}
	int a;//临时数字
	for (int i = 0; i < len; ++i) {//按位扫描后缀表达式
		if (str[i] == ' ')continue;//若为空格则跳过
		if (is_num(str[i])) {//若当前位为数字
			a = 0;
			for (; i < len; ++i) {//循环向后扫描，直到当前位不为数字为止
				if (is_num(str[i]))a = a * 10 + (int)(str[i] - '0');//如果是数字则循环累加进行记录
				else break;//不是数字则跳出循环
			}
			i--;//复位
			num[++top] = a;//将操作数压入栈中
			continue;
		}
		else {//若当前位不是数字
			if (str[i] == '+') {//若为+号
				a = num[top--];//弹出栈顶元素，用a记录
				num[top] += a;//将新的栈顶元素数值加上a，完成加法操作
			}
			else if (str[i] == '-') {//若为-号
				a = num[top--];//弹出栈顶元素，用a记录
				num[top] -= a;//将新的栈顶元素数值减去a，完成减法操作
			}
			else if (str[i] == '*') {//乘除法与加减法逻辑类似
				a = num[top--];
				num[top] *= a;
			}
			else if (str[i] == '/') {
				a = num[top--];
				num[top] /= a;
			}
		}
	}
	printf("%d\n", num[top]);//最后栈中剩余的元素即是后缀表达式的值
	return 0;
}