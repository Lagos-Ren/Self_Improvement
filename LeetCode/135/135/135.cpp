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
		int n = ratings.size();//孩子数
		if (n < 2)return 1;//n==1时特判
		if (n == 2)return ratings[0] == ratings[1] ? 2 : 3;//n==2时特判
		vector<int>Candy(n, 1);//初始化糖果，每个人至少分到1个
		for (int i = 1; i < n; ++i) {//从左往右遍历
			if (ratings[i] > ratings[i - 1])Candy[i] = max(Candy[i], Candy[i - 1] + 1);
			//若当前位置的孩子评分比左边的高，则比左边多分到一个糖果
			else Candy[i] = 1;//若评分更低，则只给一颗糖
		}
		for (int i = n - 1; i > 1; --i) {//从右往左遍历，依次处理当前位置的左边一个孩子
			if (ratings[i] < ratings[i - 1]) {//若当前位置的孩子评分比左边的更低
				if (ratings[i - 1] <= ratings[i - 2])Candy[i - 1] = max(Candy[i - 1], Candy[i] + 1);
				//且左边的孩子评分比左边的左边孩子更低，则该孩子分到的糖为max(自己已分得的，当前位置孩子分得的+1)
				else Candy[i - 1] = max(Candy[i - 1], max(Candy[i - 2] + 1, Candy[i] + 1));
				//否则左边的孩子比两边孩子评分都高，则取两边孩子分得糖果数多的再加一
			}
		}
		if (ratings[0] > ratings[1])Candy[0] = max(Candy[0], Candy[1] + 1);//特殊处理第0号孩子
		int tot = 0;
		for (int i = 0; i < n; ++i)
			tot += Candy[i];//统计所有糖果数
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