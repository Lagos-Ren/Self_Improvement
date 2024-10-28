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
	int flag[20005];
	int removeDuplicates(vector<int>& nums) {
		if (!nums.size())return 0;
		vector<int>Print;
		for (int i = 0; i < nums.size(); ++i) {
			if (flag[nums[i] + 10001] < 2)Print.push_back(nums[i]), flag[nums[i] + 10001]++;
		}
		for (int i = 0; i < Print.size(); ++i)
			nums[i] = Print[i];
		return Print.size();
	}
};

int main(){
	
	return 0;
}