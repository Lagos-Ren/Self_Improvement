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
	string Name;//�ļ���
	int Line;//��������
	int First_Place, Count;//�״γ���λ�ã�����
}Print[10];

inline bool cmp(Node a, Node b) {//������
	if (a.Count == b.Count)return a.First_Place < b.First_Place;//�������һ������˭����
	else return a.Count > b.Count;//������������ǰ��
}

int main() {
//	freopen("std.in", "r", stdin);
	string str;//�ļ���
	int li, r = 0;//������������¼��
	while (cin >> str >> li) {//ÿ����һ�д����¼�ͽ��д���
		int len = str.length(), last_slath = -1;//�ļ����ܳ��ȣ����һ����б�ܡ�\����λ��
		for (int i = 0; i < len; ++i)
			if (str[i] == '\\')last_slath = i;//�����ļ������ҵ����һ����б�ܡ�\�����ֵ�λ��
		string sub;//��ʱ��������ļ����Ӵ�
		if (last_slath < 0)sub = len > 16 ? str.substr(len - 16) : str;
		//���û�з�б����Ϊ��·���ļ���ֱ���ж��䳤���Ƿ񳬹�16�������淶�ļ�����¼��sub��
		else if (len - last_slath <= 16)sub = str.substr(last_slath + 1);
		//����з�б�ܣ���Ϊ��·���ļ���ͬ���ж��䳤���Ƿ񳬹�16
		else sub = str.substr(len - 16);//�ļ������ȳ���16��ֱ�Ӵ�len-16��ʼ���ַ���ĩβ��ȡ�Ӵ�
		bool flag = false;//�����ж����д����¼���Ƿ���ڵ�ǰ�ļ�
		for (int i = 0; i < r; ++i)
			if (Print[i].Name == sub && Print[i].Line == li)flag = true, Print[i].Count++;
		//����ļ����ƺʹ����к���ȫƥ�䣬�������1���������ֱ��break
		if (!flag)//������д����¼�в����ڵ�ǰ�ļ�����������д����¼
			Print[r].Name = sub, Print[r].Line = li, Print[r].Count = 1, Print[r].First_Place = r + 1, r++;
	}
	sort(Print, Print + r, cmp);//����Ҫ����Ĵ����¼����ĿҪ������
	for (int i = 0; i < min(r, 8); ++i)//������8��
		cout << Print[i].Name << " " << Print[i].Line << " " << Print[i].Count << endl;
	return 0;
}