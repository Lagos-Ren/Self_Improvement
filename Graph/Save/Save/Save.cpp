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
typedef char VextexType;//顶点对应的数据类型，此处为char，可以用更复杂的结构体类型
typedef int EdgeType;//边对应的数据类型
typedef struct {
	VextexType Vex[MaxVertexNum];//顶点表
	EdgeType Edge[MaxVertexNum][MaxVertexNum];//邻接矩阵（边表），如果只存放01可以用bool
	int vexnum, arcnum;//图当前的顶点数和边数
}MGraph;



int main() {

	return 0;
}