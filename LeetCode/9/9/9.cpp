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
    bool isPalindrome(int x) {
		if (x < 0)return false;
		if (!x)return true;
		vector<int>nums;
		while (x)nums.push_back(x % 10), x /= 10;
		int l = 0, r = nums.size() - 1;
		while (l < r)
			if (nums[l++] != nums[r--])return false;
		return true;
    }
};

int main(){
	
	return 0;
}