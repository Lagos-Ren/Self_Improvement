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

typedef struct Arc_Node {//弧结点
	int tailvex, headvex;//弧尾，弧头编号域
	struct Arc_Node* tlink, * hlink;//尾链域，头链域
	//InfoType info;//权值域
}Arc_Node;
typedef struct V_Node {//顶点结点
	Arc_Node* firstin, * firstout;
	//分别指向以该顶点为弧头/弧尾的第一个弧结点
	VertexType data;//顶点数据域
}V_Node, Adj_List[MaxVertexNum];
typedef struct {
	Adj_List vertices;//邻接表
	int vexnum, arcnum;//图的顶点数和弧数
}CRGraph;//CRGraph是以十字(Cross)链表存储的有向图类型

typedef struct Arc__Node {//边结点
	int ivex, jvex;//边依附的两个顶点
	struct Arc__Node* ilink, * jlink;//依附同一i/j顶点的链域
	//InfoType info;//权值域
}Arc__Node;
typedef struct V__Node {//顶点结点
	Arc__Node* firstedge;//与该顶点相连的第一条边
	VertexType data;//顶点数据域
}V__Node, Adj__List[MaxVertexNum];
typedef struct {
	Adj__List vertices;//邻接多重表
	int vexnum, arcnum;//图的顶点数和弧数
}MutiGraph;//MutiGraph是以邻接多重表存储的无向图类型



int main() {

	return 0;
}