#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define MaxVertexNum 100//������Ŀ�����ֵ
#define INF 0xfffffff//����󣨲���ͨ�ĵ�֮�����Ϊ����㵽��������Ϊ�����0��
typedef char VextexType;//�����Ӧ���������ͣ��˴�Ϊchar�������ø����ӵĽṹ������
typedef int EdgeType;//�߶�Ӧ����������
typedef struct {
	VextexType Vex[MaxVertexNum];//�����
	EdgeType Edge[MaxVertexNum][MaxVertexNum];//�ڽӾ��󣨱߱������ֻ���01������bool
	int vexnum, arcnum;//ͼ��ǰ�Ķ������ͱ���
}MGraph;



int main() {

	return 0;
}