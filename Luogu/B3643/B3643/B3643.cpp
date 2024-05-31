//AC 100pts
#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define MaxVertexNum 1007
#define MaxMGSize 500007

/*
typedef char VertexType;
typedef int EdgeType;
typedef struct {
	VertexType Vex[MaxVertexNum];
	EdgeType Edge[MaxVertexNum][MaxVertexNum];
}MGraph;
*/

typedef struct ArcNode {
	int adjvex;
	struct ArcNode* nextarc;
}ArcNode,* ArcList;
typedef struct VNode {
	int data;//已更正data的数据类型
	ArcNode* firstarc;
}VNode, AdjList[MaxVertexNum];
typedef struct {
	AdjList vertices;
}ALGraph;

int vexnum, arcnum;
int MGraph[MaxMGSize] = { 0 };

inline void Init(ALGraph &G) {
//	memset(MGraph, 0, sizeof(MGraph));
	for (int i = 1; i <= vexnum; ++i) {
		ArcList h = (ArcList)malloc(sizeof(ArcList));
		h->adjvex = 0;
		h->nextarc = NULL;
		G.vertices[i].data = 0;
		G.vertices[i].firstarc = h;
	}
	return;
}

inline int Get_K(int i, int j) {
	if (i < j)swap(i, j);
	return i * (i - 1) / 2 + j - 1;//对称矩阵压缩存储（下三角）
}

inline void MG_Insert(int i, int j) {
	if (i < j)swap(i, j);
	MGraph[Get_K(i, j)] = 1;
	return;
}

inline void MG_Print() {
	for (int i = 1; i <= vexnum; ++i) {
		for (int j = 1; j <= vexnum; ++j) {
			cout << MGraph[Get_K(i, j)];
			if (j != vexnum)cout << " ";
		}
		cout << endl;
	}
	return;
}

inline void AG_Insert(ALGraph& G, int i, int j) {//简化了邻接表的插入函数
	ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
	p->adjvex = j;
	p->nextarc = NULL;
	G.vertices[i].data++;
	ArcNode* head = G.vertices[i].firstarc;
	ArcNode* tail = G.vertices[i].firstarc->nextarc;
	if (tail == NULL) {
		G.vertices[i].firstarc->nextarc = p;
	}
	else {
		while (tail != NULL) {
			if (tail->adjvex > p->adjvex) {
				p->nextarc = tail;
				head->nextarc = p;
				break;
			}
			else {
				head = head->nextarc;
				tail = tail->nextarc;
				continue;
			}
		}
		if (tail == NULL)head->nextarc = p;
	}
	return;
}

inline void AG_Print(ALGraph& G) {//改用了更简洁的cin，cout流
	for (int i = 1; i <= vexnum; ++i) {
		if (!G.vertices[i].data) {
			cout << "0" << endl;
			continue;
		}
		cout << G.vertices[i].data << " ";
		ArcNode* Arc = G.vertices[i].firstarc->nextarc;
		while (Arc != NULL) {
			cout << Arc->adjvex;
			Arc = Arc->nextarc;
			if (Arc != NULL)cout << " ";
		}
		cout << endl;
	}
	return;
}

int main() {
	ALGraph Ag;
	int i, j;
	cin >> vexnum >> arcnum;
	Init(Ag);
	for (int k = 1; k <= arcnum; ++k) {
		cin >> i >> j;
		MG_Insert(i, j);
		AG_Insert(Ag, i, j);
		AG_Insert(Ag, j, i);
	}
	MG_Print();
	AG_Print(Ag);
	return 0;
}