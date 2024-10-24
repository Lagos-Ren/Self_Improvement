#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 114;
char cd1[N], cd2[N];

int main() {
	int len1 = 0, len2 = 0;
	char ch;
	while (ch = getchar()) {
		if (ch == '-')break;
		if (ch == ' ')continue;
		cd1[len1++] = ch;
	}
	while (ch = getchar()) {
		if (ch == EOF)break;
		if (ch == ' ')continue;
		cd2[len2++] = ch;
	}


	return 0;
}

/*
//T2
struct Node{
	string Name;
	int Line;
	int First_Place, Count;
}Print[10];

inline bool cmp(Node a, Node b) {
	if (a.Count == b.Count)return a.First_Place < b.First_Place;
	else return a.Count > b.Count;
}

int main() {
//	freopen("std2.in", "r", stdin);
	string str;
	int li, r = 0;
	while (cin >> str >> li) {
		int len = str.length(), last_slath = -1;
		for (int i = 0; i < len; ++i)
			if (str[i] == '\\')last_slath = i;
		string sub;
		if (last_slath < 0)sub = len > 16 ? str.substr(len - 16) : str;
		else if (len - last_slath <= 16)sub = str.substr(last_slath + 1);
		else sub = str.substr(len - 16);
		bool flag = false;
		for (int i = 0; i < r; ++i)
			if (Print[i].Name == sub && Print[i].Line == li)flag = true, Print[i].Count++;
		if (!flag)
			Print[r].Name = sub, Print[r].Line = li, Print[r].Count = 1, Print[r].First_Place = r + 1, r++;
	}
	sort(Print, Print + r, cmp);
	for (int i = 0; i < min(r, 8); ++i)
		cout << Print[i].Name << " " << Print[i].Line << " " << Print[i].Count << endl;
	return 0;
}
*/

/*
//T1
const int N = 30005;
int n, m, stu[N];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> stu[i];
	char op;
	int u, v;
	while (m--) {
		cin >> op >> u >> v;
		if (op == 'Q') {
			int ma = 0;
			if (u > v)swap(u, v);
			for (int i = u; i <= v; ++i)
				ma = max(ma, stu[i]);
			cout << ma << endl;
		}
		else if (op == 'U')stu[u] = v;
	}
	return 0;
}
*/