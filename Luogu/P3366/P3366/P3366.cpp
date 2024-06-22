#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 5007;//最大点数
const int MAXM = 200007;//最大边数
int n, m;
int f[MAXN];//并查集
struct Node {
	int x, y, z;
}Arc[MAXM];//边集数组

inline int Find(int x) {//并查集寻根&路径压缩
	return x == f[x] ? x : f[x] = Find(f[x]);
}

inline void Merge(int x, int y) {//并查集的合并操作
	int rx = Find(x), ry = Find(y);
	if (rx == ry)return;
	else f[ry] = rx;
	return;
}

inline bool cmp(Node u, Node v) {//结构体排序规则
	return u.z < v.z;
}

inline bool Judge() {//判断所有点是否处于同一集合
	int Root = Find(1);
	for (int i = 2; i <= n; ++i)
		if (Find(i) != Root)return false;
	return true;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)f[i] = i;//并查集初始化
	for (int i = 1; i <= m; ++i) 
		cin >> Arc[i].x >> Arc[i].y >> Arc[i].z;
	sort(Arc + 1, Arc + 1 + m, cmp);//结构体排序，需要的头文件是#include<algorithm>
	int ans = 0;//存放最小生成树各边的长度之和，int够用
	for (int i = 1; i <= m; ++i) {//遍历所有边
		if (Find(Arc[i].x) != Find(Arc[i].y)) {//若顶点x和顶点y不在同一集合
			Merge(Arc[i].x, Arc[i].y);//合并
			ans += Arc[i].z;//加上边的权值
		}
	}
	if (!Judge())cout << "orz" << endl;//若图不连通
	else cout << ans << endl;
	return 0;
}