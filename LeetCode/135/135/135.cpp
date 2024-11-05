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
		int n = ratings.size();
		if (n < 2)return 1;
		if (n == 2) {
			if (ratings[0] == ratings[1])return 2;
			else return 3;
		}
		vector<int>Candy(n, 1);
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
		for (int i = 0; i < n; ++i)
			tot += Candy[i];
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
	if (n == 2) {
		if (ratings[0] == ratings[1])cout << 2 << endl;
		else cout << 3 << endl;
	}
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