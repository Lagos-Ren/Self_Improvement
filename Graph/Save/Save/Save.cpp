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
typedef char VertexType;//�����Ӧ���������ͣ��˴�Ϊchar�������ø����ӵĽṹ������
typedef int EdgeType;//�߶�Ӧ����������
typedef struct {
	VertexType Vex[MaxVertexNum];//�����
	EdgeType Edge[MaxVertexNum][MaxVertexNum];//�ڽӾ��󣨱߱������ֻ���01������bool
	int vexnum, arcnum;//ͼ��ǰ�Ķ������ͱ���
}MGraph;

typedef struct ArcNode {//�߱���
	int adjvex;//�ñ�(��)��ָ��Ķ���λ�ã���Ӧ�������data��
	struct ArcNode* nextarc;//ָ����һ����(��)��ָ�루��Ӧ�������*next��
	//Infotype info;//����洢���Ǵ�Ȩͼ����ɼ����Ȩֵ
}ArcNode;

typedef struct VNode {//�������
	VertexType data;//������Ϣ
	ArcNode* firstarc;//ָ���һ�������ö���ı�(��)��ָ��
}VNode, AdjList[MaxVertexNum];//һά����洢��������

typedef struct {
	AdjList vertices;//�ڽӱ�
	int vexnum, arcnum;//ͼ�Ķ������ͻ���
}ALGraph;//ALGraph�����ڽӱ�洢��ͼ����

int main() {

	return 0;
}