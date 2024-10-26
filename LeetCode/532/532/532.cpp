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
    int findPairs(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int Current_Num = 11451419, diff_count = 0;
		for (int i = 0; i < nums.size() - 1; ++i) {
			if (Current_Num == nums[i])continue;
			else {
				Current_Num = nums[i];
				for (int j = i + 1; j < nums.size(); ++j) {
					if (nums[j] - Current_Num == k) {
						diff_count++;
						break;
					}
				}
			}
		}
		return diff_count;
    }
};

int main(){
	
	return 0;
}