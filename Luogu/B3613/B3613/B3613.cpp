//RE(0pts)
#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MaxVertexNum = 50007;
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

int vexnum, arcnum;

inline void Init(ALGraph& G) {
	for (int i = 1; i <= vexnum; ++i) {
		ArcList h = (ArcList)malloc(sizeof(ArcList));
		h->adjvex = 0;
		h->nextarc = NULL;
		G.vertices[i].data = 0;
		G.vertices[i].firstarc = h;
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
	return;
}

inline void AG_Print(ALGraph& G) {
	for (int i = 1; i <= vexnum; ++i) {
		if (!G.vertices[i].data) {
			cout << endl;
			continue;
		}
//		cout << G.vertices[i].data << " ";
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
	int T, n, m;
	cin >> T;
	while (T--) {
		cin >> vexnum >> arcnum;
		ALGraph G;
		Init(G);
		int u, v;
		for (int i = 1; i <= arcnum; ++i) {
			cin >> u >> v;
			AG_Insert(G, u, v);
		}
		AG_Print(G);
	}
	return 0;
}