#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 114;

inline int Judge(char ch1, char ch2) {
	if (ch1 == ch2)return 0;
	else {
		if (ch1 == 'R') {
			if (ch2 == 'S')return 1;
			else if (ch2 == 'P')return 2;
		}
		if (ch1 == 'S') {
			if (ch2 == 'P')return 1;
			else if (ch2 == 'R')return 2;
		}
		if (ch1 == 'P') {
			if (ch2 == 'R')return 1;
			else if (ch2 == 'S')return 2;
		}
	}
}

int main() {
	int n;
	cin >> n;
	char S1[N], S2[N];
	while (n--) {
		cin >> S1 >> S2;
		int flag = Judge(S1[0], S2[0]);
		if (!flag)cout << "Tie" << endl;
		else if (flag == 1)cout << "Player1" << endl;
		else cout << "Player2" << endl;
	}
	return 0;
}