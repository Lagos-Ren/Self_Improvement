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

typedef struct Arc_Node {//�����
	int tailvex, headvex;//��β����ͷ�����
	struct Arc_Node* tlink, * hlink;//β����ͷ����
	//InfoType info;//Ȩֵ��
}Arc_Node;
typedef struct V_Node {//������
	Arc_Node* firstin, * firstout;
	//�ֱ�ָ���Ըö���Ϊ��ͷ/��β�ĵ�һ�������
	VertexType data;//����������
}V_Node, Adj_List[MaxVertexNum];
typedef struct {
	Adj_List vertices;//�ڽӱ�
	int vexnum, arcnum;//ͼ�Ķ������ͻ���
}CRGraph;//CRGraph����ʮ��(Cross)����洢������ͼ����

typedef struct Arc__Node {//�߽��
	int ivex, jvex;//����������������
	struct Arc__Node* ilink, * jlink;//����ͬһi/j���������
	//InfoType info;//Ȩֵ��
}Arc__Node;
typedef struct V__Node {//������
	Arc__Node* firstedge;//��ö��������ĵ�һ����
	VertexType data;//����������
}V__Node, Adj__List[MaxVertexNum];
typedef struct {
	Adj__List vertices;//�ڽӶ��ر�
	int vexnum, arcnum;//ͼ�Ķ������ͻ���
}MutiGraph;//MutiGraph�����ڽӶ��ر�洢������ͼ����



int main() {

	return 0;
}