#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 505;
struct Node {
	int num;
	string str;
}s[N];
bool flag[N];

inline bool cmp(Node a, Node b) {
	return a.num < b.num;
}

inline bool Find(int n) {
	for (int i = 1; i < n; ++i) {
		if (s[n].str == s[i].str) {
			if (!flag[i]) {
				flag[i] = true;
				return false;
			}
			else return true;
		}
	}
	if (!flag[n]) {
		flag[n] = true;
		return false;
	}
	else return true;
}

int main() {
	int n = 0;
	string ss;
	while (cin >> ss) {
		if (ss == "0")break;
		s[++n].str = ss;
		s[n].num = n;
	}
	for (int i = 1; i <= n; ++i)
		if (!Find(i))cout << s[i].str;
	return 0;
}