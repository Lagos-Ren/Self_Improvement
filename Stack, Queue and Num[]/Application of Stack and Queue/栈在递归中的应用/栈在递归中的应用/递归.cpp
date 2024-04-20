#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

inline int fac(int n) {//递归求阶乘（极易溢出）
	if (n == 0 || n == 1)return 1;//边界条件
	else return n * fac(n - 1);//递归表达式
}

inline int fib(int n) {//递归求斐波那契数列
	if (n == 0)return 0;//边界条件
	if (n == 1)return 1;//边界条件
	return fib(n - 1) + fib(n - 2);//递归表达式
}

int main() {
	printf("10!=%d\n", fac(10));
	printf("fib(10)=%d\n", fib(10));
	return 0;
}