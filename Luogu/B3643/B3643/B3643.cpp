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
}ArcNode;
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
	ArcNode* h = (ArcNode*)malloc(sizeof(ArcNode));
	h->adjvex = 0;
	h->nextarc = NULL;
	G.vertices->data = 0;
	G.vertices->firstarc = h;
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

int main() {
	ALGraph Ag;
	int i, j;
	scanf("%d %d", &vexnum, &arcnum);
	Init(Ag);
	for (int k = 1; k <= arcnum; ++k) {
		scanf("%d %d", &i, &j);
		if (i > j)swap(i, j);
		MG_Insert(i, j);
	}
	MG_Print();
	return 0;
}