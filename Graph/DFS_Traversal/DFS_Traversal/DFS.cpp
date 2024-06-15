#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define MaxVertexNum 114
typedef struct ArcNode {
	int adjvex;
	struct ArcNode* nextarc;
}ArcNode;
typedef struct VNode {
	int data;
	ArcNode* firstarc;
}VNode, AdjList[MaxVertexNum];
typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;

bool Visited[MaxVertexNum];

inline void Visit(int i) {
	Visited[i] = true;
	printf("%d ", i);
	return;
}

inline void DFS(ALGraph G, int i) {//ע�����Բ���inline��������ϰ��
	Visit(i);//���ʳ�ʼ����i
	for (ArcNode* p = G.vertices[i].firstarc; p != NULL; p = p->nextarc) {
		//���i�������ڽӵ�
		int j = p->adjvex;
		if (!Visited[j])DFS(G, j);//��jδ�����ʣ���ݹ����j
	}
	return;
}

inline void DFSTraverse(ALGraph G) {
	for (int i = 1; i <= G.vexnum; ++i) {
		Visited[i] = false;//��ʼ�����ʱ������
		G.vertices[i].data = i;
	}
	for (int i = 1; i <= G.vexnum; ++i) {//��1��ʼ����
		if (!Visited[i])//����ǰ����δ���������DFS()
			DFS(G, i);
	}
	return;
}

#define MaxVertexNum 114
typedef struct {
	int Vex[MaxVertexNum];
	int Edge[MaxVertexNum][MaxVertexNum];
	int vexnum, arcnum;
}MGraph;

inline void DFS_(MGraph G, int i) {
	Visit(i);//���ʳ�ʼ����i
	for (int j = 1; j <= G.vexnum; ++j) {
		//���i�������ڽӵ�
		if (!Visited[j] && G.Edge[i][j])
			DFS_(G, j);//jΪi��δ���ʵ��ڽӵ㣬�ݹ����j
	}
	return;
}

int main() {
	ALGraph G;
//	DFSTraverse(G);

	return 0;
}