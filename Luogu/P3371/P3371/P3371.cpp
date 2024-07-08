//WA(30pts)
#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define MaxVertexNum 10007
#define INF 0x7fffffff

typedef struct ArcNode {
	int adjvex;
	int info;
	struct ArcNode* nextarc;
}ArcNode, * ArcList;
typedef struct VNode {
	int data;
	ArcNode* firstarc;
}VNode, AdjList[MaxVertexNum];
typedef struct {
	AdjList vertices;
	int vexnum, arcnum, Start;
}ALGraph;

bool final[MaxVertexNum];
int dist[MaxVertexNum], path[MaxVertexNum];

inline void Init(ALGraph& G) {
	for (int i = 1; i <= G.vexnum; ++i) {
		ArcList h = (ArcList)malloc(sizeof(ArcList));
		h->adjvex = -1;
		h->info = INF;
		h->nextarc = NULL;
		G.vertices[i].data = i;
		G.vertices[i].firstarc = h;
		final[i] = false, dist[i] = INF, path[i] = -1;
	}
	final[G.Start] = true, dist[G.Start] = 0;
	return;
}

inline void AG_Insert(ALGraph& G, int i, int j, int k) {
	ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
	p->adjvex = j;
	p->info = k;
	ArcNode* head = G.vertices[i].firstarc;
	ArcNode* tail = G.vertices[i].firstarc->nextarc;
	p->nextarc = tail;
	head->nextarc = p;
	return;
}

inline void Dijkstra(ALGraph G) {
	int u = G.Start, v, w;
	while (1) {
		int minn = INF, minm;
		for (ArcNode* p = G.vertices[u].firstarc; p != NULL; p = p->nextarc) {
			v = p->adjvex, w = p->info;
			if (v <= 0)continue;
			if (!final[v]) {
				if (dist[v] > dist[u] + w)
					dist[v] = dist[u] + w, path[v] = u;
				if (minn > dist[v])
					minn = dist[v], minm = v;
			}
		}
		if (minn == INF)break;
		if (!final[minm]) {
			final[minm] = true;
			u = minm;
		}
	}
	return;
}

int main() {
	ALGraph G;
	cin >> G.vexnum >> G.arcnum >> G.Start;
	Init(G);
	int u, v, w;
	for (int i = 1; i <= G.arcnum; ++i) {
		cin >> u >> v >> w;
		AG_Insert(G, u, v, w);
		if (u == G.Start)dist[v] = w, path[v] = u;
	}
	Dijkstra(G);
	for (int i = 1; i <= G.vexnum; ++i) {
		cout << dist[i];
		if (i < G.vexnum)cout << " ";
		else cout << endl;
	}
	return 0;
}