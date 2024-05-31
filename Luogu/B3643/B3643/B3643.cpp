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
#define INF 0xfffffff
typedef char VertexType;
typedef int EdgeType;

/*
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
	VertexType data;
	ArcNode* firstarc;
}VNode, AdjList[MaxVertexNum];
typedef struct {
	AdjList vertices;
}ALGraph;

int vexnum, arcnum, n;
int MGraph[MaxMGSize];

inline void Init(ALGraph &G) {
	n = vexnum * (vexnum + 1) / 2;
	memset(MGraph, 0, sizeof(MGraph));
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
	return i * (i - 1) / 2 + j - 1;//¶Ô³Æ¾ØÕóÑ¹Ëõ´æ´¢£¨ÏÂÈý½Ç£©
}

inline void MG_Insert(int i, int j) {
	if (i < j)swap(i, j);
	MGraph[Get_K(i, j)] = 1;
	return;
}

inline void MG_Print() {
	for (int i = 1; i <= vexnum; ++i) {
		for (int j = 1; j <= vexnum; ++j) {
			printf("%d", MGraph[Get_K(i, j)]);
			if (j != vexnum)printf(" ");
		}
		printf("\n");
	}
	return;
}

inline void AG_Insert(ALGraph& G, int i, int j) {
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
	ArcNode* q = (ArcNode*)malloc(sizeof(ArcNode));
	q->adjvex = i;
	q->nextarc = NULL;
	G.vertices[j].data++;
	head = G.vertices[j].firstarc;
	tail = G.vertices[j].firstarc->nextarc;
	if (tail == NULL) {
		G.vertices[j].firstarc->nextarc = q;
	}
	else {
		while (tail != NULL) {
			if (tail->adjvex > q->adjvex) {
				q->nextarc = tail;
				head->nextarc = q;
				break;
			}
			else {
				head = head->nextarc;
				tail = tail->nextarc;
				continue;
			}
		}
		if (tail == NULL)head->nextarc = q;
	}
	return;
}

inline void AG_Print(ALGraph& G) {
	for (int i = 1; i <= vexnum; ++i) {
		printf("%d ", G.vertices[i].data);
		ArcList Arc = G.vertices[i].firstarc->nextarc;
		while (Arc != NULL) {
			printf("%d", Arc->adjvex);
			Arc = Arc->nextarc;
			if (Arc != NULL)printf(" ");
		}printf("\n");
	}
	return;
}

int main() {
	ALGraph Ag;
	int i, j;
	scanf("%d %d", &vexnum, &arcnum);
	Init(Ag);
	for (int k = 1; k <= arcnum; ++k) {
		scanf("%d %d", &i, &j);
		if (i > j)swap(i, j);
		MG_Insert(i, j);
		AG_Insert(Ag, i, j);
	}
	MG_Print();
	AG_Print(Ag);
	return 0;
}