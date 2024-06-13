#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define MaxVertexNum 810
typedef struct ArcNode {
	int adjvex;
	struct ArcNode* nextarc;
}ArcNode;
typedef struct VNode {
	int data;
	ArcNode* firstarc;
}VNode,AdjList[MaxVertexNum];
typedef struct {
	AdjList vertices;//邻接表存储图
	int vexnum, arcnum;
}ALGraph;
bool Visited[MaxVertexNum];//辅助数组标记顶点是否被访问

typedef struct LinkNode {
	int Vertex;//图的顶点编号
	struct LinkNode* next;
}LinkNode;
typedef struct {
	LinkNode* front, * rear;//链队列
}LinkQueue;

void InitQueue(LinkQueue& Q) {
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode*));
	p->Vertex = -1;
	p->next = NULL;
	Q.front = Q.rear = p;//初始化队列
	return;
}

bool Q_Is_Empty(LinkQueue Q) {//队列判空
	return Q.front == Q.rear ? true : false;
}

void EnQueue(LinkQueue& Q, int i) {//新元素入队
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode*));
	p->Vertex = i;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return;
}

void DeQueue(LinkQueue& Q, int& x) {//队头元素出队
	LinkNode* p = Q.front->next;
	x = p->Vertex;
	Q.front->next = p->next;
	if (Q.rear == p)Q.rear = Q.front;
	free(p);
	return;
}

void Visit(int i) {
	printf("%d ", i);
	return;
}

void BFS(ALGraph& G, LinkQueue& Q, int i) {//广度优先搜索（对连通分量）
	Visit(i);//先访问i
	Visited[i] = true;
	EnQueue(Q, i);
	int v, w;//v记录队首元素，w用于临时记录访问的顶点
	while (!Q_Is_Empty(Q)) {//当队列不为空时
		DeQueue(Q, v);//队首元素出队
		for (ArcNode* p = G.vertices[v].firstarc; p != NULL; p = p->nextarc) {//访问p所有的邻接顶点
			w = p->adjvex;
			if (!Visited[w]) {//若顶点w未被访问过
				Visit(w);//访问顶点w
				Visited[w] = true;//对顶点w作已访问标记
				EnQueue(Q, w);//顶点w入队
			}
		}
	}
	return;
}

#define MaxVertexNum 114
typedef struct {
	int Vex[MaxVertexNum];
	int Edge[MaxVertexNum][MaxVertexNum];
	int vexnum, arcnum;
}MGraph;

void BFS_(MGraph& G, LinkQueue& Q, int i) {
	Visit(i);
	Visited[i] = true;
	EnQueue(Q, i);
	int v, w;
	while (!Q_Is_Empty(Q)) {
		DeQueue(Q, v);
		for (w = 1; w <= G.vexnum; ++w) {
			if (!Visited[w] && G.Edge[v][w]) {
				Visit(w);
				Visited[w] = true;
				EnQueue(Q, w);
			}
		}
	}
	return;
}

void BFSTraverse(ALGraph& G, LinkQueue& Q) {//对图G进行广度优先遍历
	for (int i = 1; i <= G.vexnum; ++i) {
		Visited[i] = false;//访问标记数组初始化
		G.vertices[i].data = i;//其实这一步没用
	}
	InitQueue(Q);//初始化队列
	for (int i = 1; i <= G.vexnum; ++i)//从1号顶点开始遍历
		if (!Visited[i])//对每个连通分量调用一次BFS()
			BFS(G, Q, i);//若顶点v_i未被访问过，则从顶点v_i处开始调用BFS()
	return;
}

int main() {
	ALGraph G;
	LinkQueue Q;
	BFSTraverse(G, Q);

	return 0;
}