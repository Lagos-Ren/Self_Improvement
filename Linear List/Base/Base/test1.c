#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//void test(int x) {
//	x = 1024;
//	printf("test函数内部 x=%d\n", x);
//	return;
//}
//
//int main() {
//	int x = 1;
//	printf("调用test前 x=%d\n", x);
//	test(x);
//	printf("调用test后 x=%d\n", x);//修改的结果没有带回来，x的值还是1
//	return 0;
//}

void test_114514(int* a){//C++可以直接用“&”表示引用
	*a = 1024;
	printf("test函数内部 x=%d\n", *a);
	return;
}

int main() {
	int x = 1;
	int* a = &x;
	printf("调用test前 x=%d\n", x);
	test_114514(a);
	printf("调用test后 x=%d\n", x);//修改的结果带回来后，x的值变为1024
	return 0;
}
