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
//记录各点入度，记录拓扑排序序列

inline void Init(ALGraph& G) {//预处理
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

inline void AG_Insert(ALGraph& G, int i, int j) {//头插法加入边
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
	//用静态数组模拟栈，top为栈顶指针，count为拓扑序列数组下表
	memset(Sta, 0, sizeof(Sta));
	int i;
	for (i = 1; i <= G.vexnum; ++i)
		if (!indegree[i])Sta[++top] = i;//将初始入度为0的顶点进栈
	while (top) {//当栈不空时
		i = Sta[top--];//栈顶元素出栈
		print[++count] = i;//输出顶点i
		for (ArcNode* p = G.vertices[i].firstarc; p != NULL; p = p->nextarc) {
			//将所有i指向的顶点入度减1，并将入度减为0的顶点压入栈Sta中
			int v = p->adjvex;
			if (!v)continue;
			if (!(--indegree[v]))
				Sta[++top] = v;//度为0则入栈
			p->adjvex = 0;//删除边
		}
	}
	if (count < G.vexnum)return false;//排序失败，图中存在回路
	else return true;//拓扑排序成功
}

int tim, finishtime[MaxVertexNum];//计时变量，各顶点用时数组
bool visited[MaxVertexNum];//访问标记
inline void DFSTravere(ALGraph G);
inline void DFS(ALGraph G, int v);

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
/*	if (!Topologicalsort(G))cout << "No DAG!" << endl;
	else {
		for (int i = 1; i <= G.vexnum; ++i)
			cout << print[i] << " ";
		cout << endl;
	}
*/
	DFSTravere(G);
	int con = 0;
	for (int i = 1; i <= G.vexnum; ++i) {
		int maxn = -1, maxm = 0;
		for (int j = 1; j <= G.vexnum; ++j)
			if (finishtime[j] > maxn)
				maxn = finishtime[j], maxm = j;
		finishtime[maxm] = -1;
		print[++con] = maxm;
	}
	for (int i = 1; i <= G.vexnum; ++i)
		cout << print[i] << " ";
	cout << endl;
	return 0;
}

inline void DFSTravere(ALGraph G) {
	memset(visited, false, sizeof(visited));//初始化
	memset(finishtime, 0, sizeof(finishtime));
	tim = 0;
	for (int i = 1; i <= G.vexnum; ++i)//从第一个顶点开始深搜
		if (!visited[i])DFS(G, i);
	return;
}

inline void DFS(ALGraph G, int v) {
	visited[v] = true;
	for (ArcNode* p = G.vertices[v].firstarc->nextarc; p != NULL; p = p->nextarc) {
		int w = p->adjvex;//依次遍历当前顶点的邻边未访问的顶点
		if (!visited[w])DFS(G, w);
	}
	finishtime[v] = ++tim;//搜索深度越深，tim值越小
	//如果要输出逆拓扑排序序列，只需把这一行改为输出v即可
	return;
}