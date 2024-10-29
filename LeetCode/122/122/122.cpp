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
		int Profit = 0;
		for (int i = 1; i < prices.size(); ++i)
			if (prices[i] > prices[i - 1])Profit += prices[i] - prices[i - 1];
		return Profit;
    }
};

int main(){
	
	return 0;
}