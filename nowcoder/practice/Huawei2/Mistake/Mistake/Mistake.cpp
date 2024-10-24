#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct Node {
	string Name;//文件名
	int Line;//代码行数
	int First_Place, Count;//首次出现位置，计数
}Print[10];

inline bool cmp(Node a, Node b) {//排序函数
	if (a.Count == b.Count)return a.First_Place < b.First_Place;//如果计数一样，比谁先来
	else return a.Count > b.Count;//否则计数多的排前面
}

int main() {
//	freopen("std.in", "r", stdin);
	string str;//文件名
	int li, r = 0;//代码行数，记录数
	while (cin >> str >> li) {//每读入一行错误记录就进行处理
		int len = str.length(), last_slath = -1;//文件名总长度，最后一个反斜杠“\”的位置
		for (int i = 0; i < len; ++i)
			if (str[i] == '\\')last_slath = i;//遍历文件名，找到最后一个反斜杠“\”出现的位置
		string sub;//临时变量存放文件名子串
		if (last_slath < 0)sub = len > 16 ? str.substr(len - 16) : str;
		//如果没有反斜杠则为无路径文件，直接判断其长度是否超过16，并将规范文件名记录在sub中
		else if (len - last_slath <= 16)sub = str.substr(last_slath + 1);
		//如果有反斜杠，则为有路径文件，同样判断其长度是否超过16
		else sub = str.substr(len - 16);//文件名长度超过16，直接从len-16开始到字符串末尾截取子串
		bool flag = false;//用于判断已有错误记录中是否存在当前文件
		for (int i = 0; i < r; ++i)
			if (Print[i].Name == sub && Print[i].Line == li)flag = true, Print[i].Count++;
		//如果文件名称和代码行号完全匹配，则计数加1，这里可以直接break
		if (!flag)//如果已有错误记录中不存在当前文件，则更新已有错误记录
			Print[r].Name = sub, Print[r].Line = li, Print[r].Count = 1, Print[r].First_Place = r + 1, r++;
	}
	sort(Print, Print + r, cmp);//对需要输出的错误记录按题目要求排序
	for (int i = 0; i < min(r, 8); ++i)//最多输出8条
		cout << Print[i].Name << " " << Print[i].Line << " " << Print[i].Count << endl;
	return 0;
}