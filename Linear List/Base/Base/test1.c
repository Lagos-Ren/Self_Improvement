#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//void test(int x) {
//	x = 1024;
//	printf("test�����ڲ� x=%d\n", x);
//	return;
//}
//
//int main() {
//	int x = 1;
//	printf("����testǰ x=%d\n", x);
//	test(x);
//	printf("����test�� x=%d\n", x);//�޸ĵĽ��û�д�������x��ֵ����1
//	return 0;
//}

void test_114514(int* a){//C++����ֱ���á�&����ʾ����
	*a = 1024;
	printf("test�����ڲ� x=%d\n", *a);
	return;
}

int main() {
	int x = 1;
	int* a = &x;
	printf("����testǰ x=%d\n", x);
	test_114514(a);
	printf("����test�� x=%d\n", x);//�޸ĵĽ����������x��ֵ��Ϊ1024
	return 0;
}
