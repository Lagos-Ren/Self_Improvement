#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
#define SIZE 100
int UFSets[SIZE];//����Ԫ�����飨˫��ָ�����飩

void Init() {//��ʼ��
	memset(UFSets, -1, sizeof(UFSets));
	//�����Ԫ�س�ֵ��-1����ʾÿ����Ԫ�Գɼ��ϣ����memset�ȼ��������д��
	/*
	for (int i = 0; i < SIZE; ++i)
		UFSets[i] = -1;
	*/
	return;
}

int Find(int S[], int x) {//���顱�������ҵ�x�������ϣ�����x�������ĸ���㣩
	while (S[x] >= 0)//ѭ������x�ĸ�
		x = S[x];
	return x;//����S[]С��0
}

void Union(int S[], int Root1, int Root2) {
	//���������������������Ϻϲ�Ϊһ��
	if (Root1 != Root2)S[Root2] = Root1;
	//��Root1��Root2��������ͬ�ļ��ϣ��򽫸�Root2������һ��Root1����
	return;
}

void Union_(int S[], int Root1, int Root2) {//�Ľ���ġ���������
	if (Root1 == Root2)return;//ͬһ��������ϲ�
	if (S[Root2] > S[Root1]) {//��Root2���������
		S[Root1] += S[Root2];//�ۼӼ������Ľ������
		S[Root2] = Root1;//С���ϲ�������
	}
	else {
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	}
	return;

}

int main() {

	return 0;
}
