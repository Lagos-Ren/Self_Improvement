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
		vector<int>dp(n, 0x3f3f3f3f);//��ʼ��һ������ֵ
		if (!nums[0] || n < 2)return 0;//���������0��������Ԫ��ֻ��һ���Ͳ�������
		dp[0] = 0;//��ʼ��
		for (int i = 1; i < n; ++i)
			for (int j = 0; j < i; ++j)
				if (i - j <= nums[j])dp[i] = min(dp[i], dp[j] + 1);//״̬ת�Ʒ���
		return dp[n - 1];
    }
};

int main(){
	
	return 0;
}