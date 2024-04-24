#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

#define MaxLen 259//预定义最大串长，致敬传奇指挥259
typedef struct {//静态数组存储
	char ch[MaxLen];//字符数组储存串
	int length;//串长
}SString;
int nex[MaxLen] = { 0 };
int nextval[MaxLen] = { 0 };

void InitString(SString& S) {//初始化
	S.length = 0;
	return;
}

bool StrEmpty(SString S) {//判空
	return S.length == 0 ? true : false;
}

int StrLength(SString S) {//求串长
	return S.length;
}

void StrAssign(SString& S, char c[]) {//赋值
	InitString(S);//初始化串S防止其内部残留“脏数据”
	int len = strlen(c) - 1;
	//因为采用字符数组传参，需要对其长度-1，排除数组下标为0的数据干扰
	if (len == 0)return;//如果传入的是空串，则无需操作
	else S.length = len;//否则将串长更改为len
	for (int i = 1; i <= len; ++i)
		S.ch[i] = c[i];//按位传入字符串
	return;
}

void StrCopy(SString& S, SString& T) {//复制
	S.length = T.length;
	for (int i = 1; i <= T.length; ++i)
		S.ch[i] = T.ch[i];
	return;
}

void Contact(SString& S, char T1[], char T2[]) {//串联接，用S返回T1,T2拼接成的新串
	int len1 = strlen(T1) - 1, len2 = strlen(T2) - 1, i;
	//len1表示T1串长，len2表示T2串长，i表示联接串数组下标
	for (i = 1; i <= len1; ++i)
		S.ch[i] = T1[i];//先复制T1串
	for (int j = 1; j <= len2; ++i, ++j)
		S.ch[i] = T2[j];//再在其后复制T2串
	S.length = len1 + len2;//新串的长度等于两串长度和
	return;
}

bool SubString(SString& Sub, SString S, int pos, int len) {
	//查找S串中，在pos位置开始，长度为len的子串，并用Sub返回
	if (pos + len - 1 > S.length)return false;//如果子串位置和长度非法直接返回false
	for (int i = pos; i < pos + len; ++i)//从pos处开始，到pos+len-1处结束 
		Sub.ch[i - pos + 1] = S.ch[i];
	Sub.length = len;//子串长度就是len
	return true;
}

int StrCompare(SString S, SString T) {//比较串大小
	//若S串＞T串，返回值＞0；若S串=T串，返回值=0；若S串＜T串，返回值＜0
	for (int i = 1; i <= S.length && i <= T.length; ++i)
		if (S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	return S.length - T.length;//长的串值更大
}
/*
int Index(SString S, SString T) {//查询子串T在主串S中的位置
	SString Sub;//临时子串Sub
	for (int i = 1; i <= S.length - T.length + 1; ++i) {
		SubString(Sub, S, i, T.length);//从位置1开始查找，并用Sub临时存放子串
		if (StrCompare(Sub, T) != 0)continue;//比较Sub和T，如果不同则继续循环
		else return i;//否则返回i，即T在S中第一次出现的位置
	}
	return 0;//若未找到则返回0
}
*/
int Index(SString S, SString T) {//朴素模式匹配算法
	int i = 1, j = 1;
	for (; i <= S.length && j <= T.length; ++i, ++j) {
		if (S.ch[i] == T.ch[j])continue;
		else {
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > T.length)return i - T.length;
	else return 0;
}//最坏时间复杂度为O(nm)

int Index_KMP(SString S, SString T) {//KMP算法
	int i = 1, j = 1;
	for (; i <= S.length && j <= T.length; ++i, ++j) {
		if (j == 0 || S.ch[i] == T.ch[j])continue;
		//若j为0或当前位匹配成功，则继续匹配
//		else j = nex[j];//否则向右移动模式串
		else j = nextval[j];
	}
	if (j > T.length)return i - T.length;//匹配成功
	else return 0;//匹配失败返回0
}//最坏时间复杂度O(n+m)

void Get_Next(SString S) {//获取next数组
	nex[1] = 0, nex[2] = 1;
	for (int i = 1, j = 0; i < S.length;) {
		//i记录next数组下标，j记录模式串前缀下标
		if (j == 0 || S.ch[i] == S.ch[j])nex[++i] = ++j;
		//若第i位和第j位匹配，则与主串匹配时到模式串的第i位不匹配的话，模式串直接移动到第j位
		//若能一直匹配下去，则next值的计算实际上等价于next[j+1]=next[j]+1
		else j = nex[j];//否则令j=next[j]，若无next值则会让j回到0
	}
/*	//王道书上写法如下
	int i = 1, j = 0;
	nex[1] = 0;
	while (i < S.length) {
		if (j == 0 || S.ch[i] == S.ch[j]) {
			++i, ++j;
			nex[i] = j;//若pi=pj，则next[j+1]=next[j]+1
		}
		else j = nex[j];//否则令j=next[j]，循环继续
	}
*/	return;
}

void Get_Val(SString S) {//从预处理的next数组得到nextval数组
	for (int i = 1; i <= S.length; ++i) {//按位循环处理模式串
		if (S.ch[i] == S.ch[nex[i]])nextval[i] = nex[nex[i]];
		//若第i位与第next[i]位字符相同，则nextval[i]直接等于next[i]的next值
		else nextval[i] = nex[i];//否则nextval[i]的值与next[i]的值一样
	}
	return;
}

void Get_NextVal(SString S) {//直接求nextval数组
	nextval[1] = 0;//第1位的nextval值一定为0
	for (int i = 1, j = 0; i < S.length;) {//循环处理模式串，i为nextval数组下标
		if (j == 0 || S.ch[i] == S.ch[j]) {
			//若j为0，或者第i位和第j位匹配成功
			++i, ++j;//继续后移一位i和j
			if (S.ch[i] != S.ch[j])nextval[i] = j;
			//若后一位不匹配，则说明匹配到第i位时失配可直接跳到第j位
			else nextval[i] = nextval[j];
			//若后一位匹配，则匹配到第i位失配时跳到的位置和第j位失配跳到的位置相同
		}
		else j = nextval[j];//匹配失败，j跳到nextval[j]的位置
	}
	return;
}

int main() {
	SString S, T;
	InitString(S), InitString(T);
	for (int i = 1; i <= 9; ++i) {
		if (i == 4 || i == 9)S.ch[i] = 'b';
		else S.ch[i] = 'a';
	}
	S.length = 9;
	T.ch[1] = T.ch[2] = T.ch[3] = T.ch[4] = 'a';
	T.ch[5] = 'b';
	T.length = 5;
	Get_Next(T);
	Get_NextVal(T);
	printf("next:%d %d %d %d %d\n", nex[1], nex[2], nex[3], nex[4], nex[5]);
	printf("nextval:%d %d %d %d %d\n", nextval[1], nextval[2], nextval[3], nextval[4], nextval[5]);
	printf("KMP=%d\n", Index_KMP(S, T));
	return 0;
}