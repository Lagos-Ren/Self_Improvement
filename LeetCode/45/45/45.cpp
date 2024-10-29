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
    int jump(vector<int>& nums) {
		int n = nums.size();
		vector<int>dp(n, 0x3f3f3f3f);//初始赋一个极大值
		if (!nums[0] || n < 2)return 0;//如果起点就是0或者数组元素只有一个就不用跳了
		dp[0] = 0;//初始化
		for (int i = 1; i < n; ++i)
			for (int j = 0; j < i; ++j)
				if (i - j <= nums[j])dp[i] = min(dp[i], dp[j] + 1);//状态转移方程
		return dp[n - 1];
    }
};

int main(){
	
	return 0;
}