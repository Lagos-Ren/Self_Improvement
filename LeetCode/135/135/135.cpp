#define _CRT_SECURE_NO_WARNINGS 1 
#include<cmath>
#include<cstdio>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
		int n = ratings.size();//������
		if (n < 2)return 1;//n==1ʱ����
		if (n == 2)return ratings[0] == ratings[1] ? 2 : 3;//n==2ʱ����
		vector<int>Candy(n, 1);//��ʼ���ǹ���ÿ�������ٷֵ�1��
		for (int i = 1; i < n; ++i) {//�������ұ���
			if (ratings[i] > ratings[i - 1])Candy[i] = max(Candy[i], Candy[i - 1] + 1);
			//����ǰλ�õĺ������ֱ���ߵĸߣ������߶�ֵ�һ���ǹ�
			else Candy[i] = 1;//�����ָ��ͣ���ֻ��һ����
		}
		for (int i = n - 1; i > 1; --i) {//����������������δ���ǰλ�õ����һ������
			if (ratings[i] < ratings[i - 1]) {//����ǰλ�õĺ������ֱ���ߵĸ���
				if (ratings[i - 1] <= ratings[i - 2])Candy[i - 1] = max(Candy[i - 1], Candy[i] + 1);
				//����ߵĺ������ֱ���ߵ���ߺ��Ӹ��ͣ���ú��ӷֵ�����Ϊmax(�Լ��ѷֵõģ���ǰλ�ú��ӷֵõ�+1)
				else Candy[i - 1] = max(Candy[i - 1], max(Candy[i - 2] + 1, Candy[i] + 1));
				//������ߵĺ��ӱ����ߺ������ֶ��ߣ���ȡ���ߺ��ӷֵ��ǹ�������ټ�һ
			}
		}
		if (ratings[0] > ratings[1])Candy[0] = max(Candy[0], Candy[1] + 1);//���⴦���0�ź���
		int tot = 0;
		for (int i = 0; i < n; ++i)
			tot += Candy[i];//ͳ�������ǹ���
		return tot;
    }
};

int main(){
	freopen("std.in", "r", stdin);
	vector<int> ratings;
	int a;
	while (cin >> a)ratings.push_back(a);
	int n = ratings.size();
	if (n < 2)cout << 1 << endl;
	if (n == 2)ratings[0] == ratings[1] ? cout << 2 << endl : cout << 3 << endl;
	else {
		vector<int>Candy(n, 1);
		if (ratings[0] > ratings[1])Candy[0]++;
		for (int i = 1; i < n; ++i) {
			if (ratings[i] > ratings[i - 1])Candy[i] = max(Candy[i], Candy[i - 1] + 1);
			else Candy[i] = 1;
		}
		for (int i = n - 1; i > 1; --i) {
			if (ratings[i] < ratings[i - 1]) {
				if (ratings[i - 1] <= ratings[i - 2])Candy[i - 1] = max(Candy[i - 1], Candy[i] + 1);
				else Candy[i - 1] = max(Candy[i - 1], max(Candy[i - 2] + 1, Candy[i] + 1));
			}
		}
		if (ratings[0] > ratings[1])Candy[0] = max(Candy[0], Candy[1] + 1);
		int tot = 0;
		for (int i = 0; i < n; ++i) {
			cout << Candy[i] << " ";
			tot += Candy[i];
		}
		cout << endl;
		cout << tot << endl;
	}
	return 0;
}