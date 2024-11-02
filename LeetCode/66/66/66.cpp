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
    vector<int> plusOne(vector<int>& digits) {
		vector<int>nums;
		while (digits.size())
			nums.push_back(digits[digits.size() - 1]), digits.pop_back();
		nums[0]++;
		for (int i = 0; i < nums.size() - 1; ++i)
			if (nums[i] > 9)nums[i] -= 10, nums[i + 1]++;
		if (nums[nums.size() - 1] > 9)nums[nums.size() - 1] -= 10, nums.push_back(1);
		reverse(nums.begin(), nums.end());
		return nums;
    }
};

int main(){
	
	return 0;
}