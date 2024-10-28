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
	void rotate(vector<int>& nums, int k) {
		if (!k || nums.size() < 2)return;
		int n = nums.size();
		vector<int>Temp(nums);
		for (int i = 0; i < n; ++i) {
			int j = i - k;
			while (j < 0)j += n;
			nums[i] = Temp[j];
		}
		return;
	}
};

int main(){
	
	return 0;
}