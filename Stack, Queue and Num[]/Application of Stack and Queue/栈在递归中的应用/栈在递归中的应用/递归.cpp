#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

inline int fac(int n) {//�ݹ���׳ˣ����������
	if (n == 0 || n == 1)return 1;//�߽�����
	else return n * fac(n - 1);//�ݹ���ʽ
}

inline int fib(int n) {//�ݹ���쳲���������
	if (n == 0)return 0;//�߽�����
	if (n == 1)return 1;//�߽�����
	return fib(n - 1) + fib(n - 2);//�ݹ���ʽ
}

int main() {
	printf("10!=%d\n", fac(10));
	printf("fib(10)=%d\n", fib(10));
	return 0;
}