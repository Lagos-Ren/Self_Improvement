#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define MaxVertexNum 810
#define INF 0x7fffffff
//INF就是无穷大

typedef struct ArcNode {
	int adjvex;
	struct ArcNode* nextarc;
}ArcNode;
typedef struct VNode {
	int data;
	ArcNode* firstarc;
}VNode, AdjList[MaxVertexNum];
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

//求顶点u到其他顶点的最短路径
void BFS_MIN_Distance(ALGraph G, LinkQueue& Q, int u) {
	int d[MaxVertexNum], path[MaxVertexNum], v;
	//d[i]表示从u到i结点的最短路径；path[i]表示顶点u到顶点i的最短路径上，顶点i的直接前驱
	memset(d, INF, sizeof(d));//初始化路径长度为无穷大
	memset(path, -1, sizeof(path));//初始化所有顶点的直接前驱为-1
	Visited[u] = true, d[u] = 0;
	EnQueue(Q, u);
	while (!Q_Is_Empty(Q)) {//BFS主过程
		DeQueue(Q, u);//队头元素出队
		for (ArcNode* w = G.vertices[u].firstarc; w != NULL; w = w->nextarc) {
			//遍历u的所有邻接点
			v = w->adjvex;
			if (!Visited[v]) {//若未访问
				Visited[v] = true;//标记访问
				d[v] = d[u] + 1;//路径长度加1
				path[v] = u;//最短路径中，应是从u到v
				EnQueue(Q, v);//顶点w入队
			}
		}
	}
	return;
}

/*
void BFS(ALGraph& G, LinkQueue& Q, int i) {//广度优先搜索（对连通分量）
	Visit(i);//先访问i
	Visited[i] = true;
	EnQueue(Q, i);
	int v, w;//v记录队首元素，w用于临时记录访问的顶点
	while (!Q_Is_Empty(Q)) {//当队列不为空时
		DeQueue(Q, v);//队首元素出队
		for (ArcNode* p = G.vertices[v].firstarc; p != NULL; p = p->nextarc) {
			//访问v所有的邻接顶点
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
*/

int main() {
	
	return 0;
}