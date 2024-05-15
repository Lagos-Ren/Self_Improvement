#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
#define SIZE 100
int UFSets[SIZE];//����Ԫ�����飨˫��ָ�����飩

void Init(int S[]) {//��ʼ��
	memset(S, -1, sizeof(S));
	//�����Ԫ�س�ֵ��-1����ʾÿ����Ԫ�Գɼ��ϣ����memset�ȼ��������д��
	/*
	for (int i = 0; i < SIZE; ++i)
		S[i] = -1;
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
	else {//Root1���������
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	}
	return;
}

int Find_(int S[], int x) {//�Ľ���ġ��顱����
	int root = x;
	while (S[root] >= 0)root = S[root];//ѭ���ҵ���
	for (int t; x != root; t = S[x], S[x] = root, x = t);//·��ѹ��
	/*forѭ���ȼ��������whileѭ��
	while (x != root) {
		int t = S[x];
		S[x] = root;
		x = t;
	}
	*/
	return root;//���ظ�
}

int main() {

	return 0;
}
