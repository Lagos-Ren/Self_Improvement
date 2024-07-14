#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define MaxVertexNum 1007
typedef struct ArcNode {
	int adjvex;
	struct ArcNode* nextarc;
}ArcNode, * ArcList;
typedef struct VNode {
	int data;
	ArcNode* firstarc;
}VNode, AdjList[MaxVertexNum];
typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;

int indegree[MaxVertexNum], print[MaxVertexNum];
//��¼������ȣ���¼������������

inline void Init(ALGraph& G) {//Ԥ����
	for (int i = 1; i <= G.vexnum; ++i) {
		ArcList h = (ArcList)malloc(sizeof(ArcList));
		h->adjvex = 0;
		h->nextarc = NULL;
		G.vertices[i].data = 0;
		G.vertices[i].firstarc = h;
	}
	memset(indegree, 0, sizeof(indegree));
	memset(print, 0, sizeof(print));
	return;
}

inline void AG_Insert(ALGraph& G, int i, int j) {//ͷ�巨�����
	ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
	p->adjvex = j;
	ArcNode* head = G.vertices[i].firstarc;
	ArcNode* tail = G.vertices[i].firstarc->nextarc;
	p->nextarc = tail;
	head->nextarc = p;
	return;
}

inline bool Topologicalsort(ALGraph G) {
	int Sta[MaxVertexNum], top = 0, count = 0;
	//�þ�̬����ģ��ջ��topΪջ��ָ�룬countΪ�������������±�
	memset(Sta, 0, sizeof(Sta));
	int i;
	for (i = 1; i <= G.vexnum; ++i)
		if (!indegree[i])Sta[++top] = i;//����ʼ���Ϊ0�Ķ����ջ
	while (top) {//��ջ����ʱ
		i = Sta[top--];//ջ��Ԫ�س�ջ
		print[++count] = i;//�������i
		for (ArcNode* p = G.vertices[i].firstarc; p != NULL; p = p->nextarc) {
			//������iָ��Ķ�����ȼ�1��������ȼ�Ϊ0�Ķ���ѹ��ջSta��
			int v = p->adjvex;
			if (!v)continue;
			if (!(--indegree[v]))
				Sta[++top] = v;//��Ϊ0����ջ
			p->adjvex = 0;
		}
	}
	if (count < G.vexnum)return false;//����ʧ�ܣ�ͼ�д��ڻ�·
	else return true;//��������ɹ�
}

int main() {
	ALGraph G;
	cin >> G.vexnum;
	Init(G);
	for (int i = 1, j; i <= G.vexnum; ++i) {
		for (int k = 0; k <= G.vexnum; ++k) {
			cin >> j;
			if (!j)break;
			AG_Insert(G, i, j);
			indegree[j]++;
		}
	}
	if (!Topologicalsort(G))cout << "No DAG!" << endl;
	else {
		for (int i = 1; i <= G.vexnum; ++i)
			cout << print[i] << " ";
		cout << endl;
	}
	return 0;
}