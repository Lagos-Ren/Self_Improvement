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
    int majorityElement(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		int k = nums[0], Count = 1;
		for (int i = 1; i < n; ++i) {
			if (nums[i] == k)Count++;
			else k = nums[i], Count = 1;
			if (Count > floor(n / 2))break;
		}
		return k;
    }
};

int main(){
	
	return 0;
}