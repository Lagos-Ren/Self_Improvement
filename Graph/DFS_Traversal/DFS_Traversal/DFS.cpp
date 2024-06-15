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

inline void DFS(ALGraph G, int i) {//注：可以不加inline，仅个人习惯
	Visit(i);//访问初始顶点i
	for (ArcNode* p = G.vertices[i].firstarc; p != NULL; p = p->nextarc) {
		//检测i的所有邻接点
		int j = p->adjvex;
		if (!Visited[j])DFS(G, j);//若j未被访问，则递归访问j
	}
	return;
}

inline void DFSTraverse(ALGraph G) {
	for (int i = 1; i <= G.vexnum; ++i) {
		Visited[i] = false;//初始化访问标记数组
		G.vertices[i].data = i;
	}
	for (int i = 1; i <= G.vexnum; ++i) {//从1开始遍历
		if (!Visited[i])//若当前顶点未访问则调用DFS()
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
	Visit(i);//访问初始顶点i
	for (int j = 1; j <= G.vexnum; ++j) {
		//检查i的所有邻接点
		if (!Visited[j] && G.Edge[i][j])
			DFS_(G, j);//j为i尚未访问的邻接点，递归访问j
	}
	return;
}

int main() {
	ALGraph G;
//	DFSTraverse(G);

	return 0;
}