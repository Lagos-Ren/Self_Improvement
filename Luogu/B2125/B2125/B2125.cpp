#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct Student {
	int data;
	char name[25];
}S[114];
int n;

inline bool cmp(Student a, Student b) {
	return a.data > b.data;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> S[i].data >> S[i].name;
	sort(S, S + n, cmp);
	cout << S[0].name << endl;
	return 0;
}