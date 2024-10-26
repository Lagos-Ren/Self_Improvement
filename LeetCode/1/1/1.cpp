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
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int>Find;
		bool flag = false;
		for (int i = 0; i < nums.size(); ++i) {
			if (flag)break;
			for (int j = i + 1; j < nums.size(); ++j) {
				if (nums[i] + nums[j] == target) {
					flag = true, Find.push_back(i), Find.push_back(j);
					break;
				}
			}
		}
		return Find;
    }
};

int main(){
	
	return 0;
}