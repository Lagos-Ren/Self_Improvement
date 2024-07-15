#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 114;
int n, indegree[N], print[N];//顶点数，各点入度，拓扑序列数组
bool A[N][N];//邻接矩阵存图
int outdegree[N];//出度

inline void Init() {
	cin >> n;
	for (int i = 0; i <= n; ++i) {//初始化
		indegree[i] = 0;
		outdegree[i] = 0;
		for (int j = 0; j <= n; ++j) {
			A[i][j] = false;
		}
	}
	for (int i = 1, j; i <= n; ++i) {
		for (int k = 0; k <= n; ++k) {
			cin >> j;
			if (!j)break;//读到0结束当前顶点的后代读入
			A[i][j] = true;//邻接矩阵加入有向边
			indegree[j]++;//后代的入度加1
			outdegree[i]++;
		}
	}
	return;
}

inline bool TopologicalSort() {//拓扑排序
	int Sta[N], top = 0, count = 0;//静态数组模拟栈
	memset(Sta, 0, sizeof(Sta));//初始化栈
	int i;
	for (i = 1; i <= n; ++i)
		if (!indegree[i])Sta[++top] = i;//入度为0的顶点入栈
	while (top) {
		i = Sta[top--];//栈顶元素出栈
		print[++count] = i;//输出i
		for (int j = 1; j <= n; ++j)
			if (A[i][j]) {//若i到j直接存在一条边
				A[i][j] = false, indegree[j]--;//删除该边，j的入度减1
				if (!indegree[j])Sta[++top] = j;//若j的入度减为0，则入栈
			}
	}
	if (count < n)return false;//若计数小于顶点数，说明存在环
	else return true;//否则拓扑排序成功
}

inline bool ReverTopoSort();//逆拓扑排序

int main() {
	Init();
	if (!TopologicalSort())cout << "Error!" << endl;//排序失败
	else {//排序成功
		for (int i = 1; i <= n; ++i)
			cout << print[i] << " ";//输出拓扑排序序列
		cout << endl;
	}
	return 0;
}

inline bool ReverTopoSort() {
	int Sta[N], top = 0, count = 0;//静态数组模拟栈
	memset(Sta, 0, sizeof(Sta));
	int i;
	for (i = 1; i <= n; ++i)
		if (!outdegree[i])Sta[++top] = i;//出度为0的点入栈
	while (top) {//当栈不为空时
		i = Sta[top--];//弹出栈顶元素
		print[++count] = i;//输出
		for (int j = 1; j <= n; ++j)
			if (A[j][i]) {//如果有一条j到i的边
				A[j][i] = false, outdegree[j]--;//删除之，使顶点j的出度减1
				if (!outdegree[j])Sta[++top] = j;//如果顶点j的出度为0则入栈
			}
	}
	if (count < n)return false;//有环
	else return true;
}