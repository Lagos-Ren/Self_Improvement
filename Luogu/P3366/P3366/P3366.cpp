#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 5007;
const int MAXM = 200007;
int n, m;
int f[MAXN];
struct Node {
	int x, y, z;
}Arc[MAXM];

inline int Find(int x) {
	return x == f[x] ? x : f[x] = Find(f[x]);
}

inline void Merge(int x, int y) {
	int rx = Find(x), ry = Find(y);
	if (rx == ry)return;
	else f[ry] = rx;
	return;
}

inline bool cmp(Node u, Node v) {
	return u.z < v.z;
}

inline bool Judge() {
	int Root = Find(1);
	for (int i = 2; i <= n; ++i)
		if (Find(i) != Root)return false;
	return true;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)f[i] = i;
	for (int i = 1; i <= m; ++i) 
		cin >> Arc[i].x >> Arc[i].y >> Arc[i].z;
	sort(Arc + 1, Arc + 1 + m, cmp);
	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		if (Find(Arc[i].x) != Find(Arc[i].y)) {
			Merge(Arc[i].x, Arc[i].y);
			ans += Arc[i].z;
		}
	}
	if (!Judge())cout << "orz" << endl;
	else cout << ans << endl;
	return 0;
}