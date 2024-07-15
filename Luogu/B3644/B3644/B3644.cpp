#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 114;
int n, indegree[N], print[N];//��������������ȣ�������������
bool A[N][N];//�ڽӾ����ͼ
int outdegree[N];//����

inline void Init() {
	cin >> n;
	for (int i = 0; i <= n; ++i) {//��ʼ��
		indegree[i] = 0;
		outdegree[i] = 0;
		for (int j = 0; j <= n; ++j) {
			A[i][j] = false;
		}
	}
	for (int i = 1, j; i <= n; ++i) {
		for (int k = 0; k <= n; ++k) {
			cin >> j;
			if (!j)break;//����0������ǰ����ĺ������
			A[i][j] = true;//�ڽӾ�����������
			indegree[j]++;//�������ȼ�1
			outdegree[i]++;
		}
	}
	return;
}

inline bool TopologicalSort() {//��������
	int Sta[N], top = 0, count = 0;//��̬����ģ��ջ
	memset(Sta, 0, sizeof(Sta));//��ʼ��ջ
	int i;
	for (i = 1; i <= n; ++i)
		if (!indegree[i])Sta[++top] = i;//���Ϊ0�Ķ�����ջ
	while (top) {
		i = Sta[top--];//ջ��Ԫ�س�ջ
		print[++count] = i;//���i
		for (int j = 1; j <= n; ++j)
			if (A[i][j]) {//��i��jֱ�Ӵ���һ����
				A[i][j] = false, indegree[j]--;//ɾ���ñߣ�j����ȼ�1
				if (!indegree[j])Sta[++top] = j;//��j����ȼ�Ϊ0������ջ
			}
	}
	if (count < n)return false;//������С�ڶ�������˵�����ڻ�
	else return true;//������������ɹ�
}

inline bool ReverTopoSort();//����������

int main() {
	Init();
	if (!TopologicalSort())cout << "Error!" << endl;//����ʧ��
	else {//����ɹ�
		for (int i = 1; i <= n; ++i)
			cout << print[i] << " ";//���������������
		cout << endl;
	}
	return 0;
}

inline bool ReverTopoSort() {
	int Sta[N], top = 0, count = 0;//��̬����ģ��ջ
	memset(Sta, 0, sizeof(Sta));
	int i;
	for (i = 1; i <= n; ++i)
		if (!outdegree[i])Sta[++top] = i;//����Ϊ0�ĵ���ջ
	while (top) {//��ջ��Ϊ��ʱ
		i = Sta[top--];//����ջ��Ԫ��
		print[++count] = i;//���
		for (int j = 1; j <= n; ++j)
			if (A[j][i]) {//�����һ��j��i�ı�
				A[j][i] = false, outdegree[j]--;//ɾ��֮��ʹ����j�ĳ��ȼ�1
				if (!outdegree[j])Sta[++top] = j;//�������j�ĳ���Ϊ0����ջ
			}
	}
	if (count < n)return false;//�л�
	else return true;
}