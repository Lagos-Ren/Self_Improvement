#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define MaxVertexNum 100//顶点数目的最大值
#define INF 0xfffffff//无穷大（不连通的点之间距离为无穷，点到自身距离可为无穷或0）
typedef char VertexType;//顶点对应的数据类型，此处为char，可以用更复杂的结构体类型
typedef int EdgeType;//边对应的数据类型
typedef struct {
	VertexType Vex[MaxVertexNum];//顶点表
	EdgeType Edge[MaxVertexNum][MaxVertexNum];//邻接矩阵（边表），如果只存放01可以用bool
	int vexnum, arcnum;//图当前的顶点数和边数
}MGraph;

typedef struct ArcNode {//边表结点
	int adjvex;//该边(弧)所指向的顶点位置（对应单链表的data）
	struct ArcNode* nextarc;//指向下一条边(弧)的指针（对应单链表的*next）
	//Infotype info;//如果存储的是带权图，则可加入边权值
}ArcNode;

typedef struct VNode {//顶点表结点
	VertexType data;//顶点信息
	ArcNode* firstarc;//指向第一条依附该顶点的边(弧)的指针
}VNode, AdjList[MaxVertexNum];//一维数组存储各个顶点

typedef struct {
	AdjList vertices;//邻接表
	int vexnum, arcnum;//图的顶点数和弧数
}ALGraph;//ALGraph是以邻接表存储的图类型

int main() {

	return 0;
}