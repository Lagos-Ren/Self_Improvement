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
    int maxProfit(vector<int>& prices) {
		if (prices.size() < 2)return 0;
		int Maxn = 0, Minn = prices[0];
		for (int i = 1; i < prices.size(); ++i) {
			Minn = min(Minn, prices[i - 1]);
			Maxn = max(Maxn, prices[i] - Minn);
		}
		return Maxn;
    }
};

int main(){
	
	return 0;
}