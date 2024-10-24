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
int len1, len2;
char card1[N], card2[N];
char cmp[13] = { '3','4','5','6','7','8','9','1','J','Q','K','A','2' };

inline int Num(char ch) {
	for (int i = 0; i < 13; ++i) {
		if (cmp[i] == ch)return i;
	}
	return 0;
}

inline void Print(int op) {
	if (op == 1) {
		for (int i = 0; i < len1; ++i) {
			cout << card1[i];
			if (card1[i] != '1')cout << " ";
		}
	}
	else if (op == 2) {
		for (int i = 0; i < len2; ++i) {
			cout << card2[i];
			if (card2[i] != '1')cout << " ";
		}
	}
	return;
}

int main() {
	freopen("std.in", "r", stdin);
	char ch;
	while (ch = getchar()) {
		if (ch == '-')break;
		else if (ch == ' ')continue;
		else card1[len1++] = ch;
	}
	while (ch = getchar()) {
		if (ch == EOF)break;
		else if (ch == ' ')continue;
		else card2[len2++] = ch;
	}
//	len2--;
	if (len1 != len2) {//手牌长度不等
		if (len1 > 8 || len2 > 8)cout << "joker JOKER" << endl;//王炸
		else if ((len1 * 2 == len2) || (len1 == len2 * 2)) {//有10的单张，对子，三张，炸弹
			if (Num(card1[0]) > Num(card2[0]))Print(1);
			else Print(2);
		}
		else if ((len1 == 4 && (card1[0] == card1[1])) || len1 == 8)Print(1);//炸弹
		else if ((len2 == 4 && (card2[0] == card2[1])) || len2 == 8)Print(2);//炸弹
		else if (len1 == 6 && len2 == 5)Print(1);//有10的顺子
		else if (len2 == 6 && len1 == 5)Print(2);//有10的顺子
		else if (len1 == 5) {//单张王
			if (card1[0] == 'J')cout << "JOKER" << endl;
			else if (card1[0] == 'j')cout << "joker" << endl;
			else cout << "ERROR";
		}
		else if (len2 == 5) {//单张王
			if (card2[0] == 'J')cout << "JOKER" << endl;
			else if (card2[0] == 'j')cout << "joker" << endl;
			else cout << "ERROR";
		}
		else cout << "ERROR";
	}
	else if (len1 == len2) {//手牌长度相等
		int len = len1;
		if (len == 5) {//长度为5
			//大小王比较
			if((card1[0]=='J'&&card2[0]=='j')|| (card1[0] == 'j' && card2[0] == 'J'))cout << "JOKER" << endl;
			else cout << "ERROR";//否则就是王和顺子比
		}
		else if (len == 4) {
			if ((card1[0] == card1[1])&& (card2[0] != card2[1]))Print(1);//炸弹
			else if ((card2[0] == card2[1]) && (card1[0] != card1[1]))Print(2);//炸弹
			else if (Num(card1[0]) > Num(card2[0]))Print(1);
			else if (Num(card1[0]) < Num(card2[0]))Print(2);
			else cout << "ERROR";
		}
		else if (len == 2) {
			if ((card1[0] == '1' && card2[0] != '1')|| (card1[0] != '1' && card2[0] == '1'))
				cout << "ERROR";//特判单张10和对子比
			else if (Num(card1[0]) > Num(card2[0]))Print(1);
			else Print(2);
		}
		else {//顺子，炸弹，三张，对子，单张都可以这么比
			if (Num(card1[0]) > Num(card2[0]))Print(1);
			else Print(2);
		}
	}
	else cout << "ERROR";
	return 0;
}