#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define MaxVertexNum 10007
#define MaxArcNum 500007
#define INF 0xfffffff

typedef struct ArcNode {
	int headvex, tailvex, info;
//	struct ArcNode* tlink, * hlink;
}ArcNode;
ArcNode ArcList[MaxArcNum];

int Vexnum, Arcnum, Sta;
bool final[MaxVertexNum];
int dist[MaxVertexNum], path[MaxVertexNum];

inline void Init() {
	cin >> Vexnum >> Arcnum >> Sta;
	memset(final, false, sizeof(final));
	memset(dist, INF, sizeof(dist));
	memset(path, 0, sizeof(path));
	final[Sta] = true, dist[Sta] = 0;
	return;
}

inline void InsertArc(int u, int v, int w, int i) {
	ArcList[i].headvex = u, ArcList[i].tailvex = v, ArcList[i].info = w;
	return;
}

inline void Dijkstra(int n) {
	while (n--) {
		

	}
	return;
}

int main() {
	Init();
	int u, v, w;
	for (int i = 1; i <= Arcnum; ++i) {
		cin >> u >> v >> w;
		InsertArc(u, v, w, i);
	}
	Dijkstra(Vexnum);


	return 0;
}