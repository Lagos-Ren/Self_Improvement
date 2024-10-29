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
    bool canJump(vector<int>& nums) {
		int n = nums.size(), Zero_pos = -1;//记录0的位置
		for (int i = n - 1; i >= 0; --i) {
			if (!nums[i]) {
				Zero_pos = i;//找到第一个0所在位置，退出遍历
				break;
			}
		}
		if (Zero_pos < 0)return true;//如果没有0，一定可以到达终点
		else if (!Zero_pos)return n < 2;//如果nums[0]=0，则只需判断数组大小是否为1即可
		else {//否则需要继续处理
			bool flag = false;//标记
			for (int i = Zero_pos; i >= 0; --i) {
				if (Zero_pos == n - 1 && Zero_pos - i <= nums[i])flag = true;
				//如果0位于终点，则影响不大，只要前面有能到达终点的元素就可以
				else if (Zero_pos - i < nums[i])flag = true;
				//否则，如果要越过当前0所在位置，则前面必须有元素的值大于0到它的距离
				if (!nums[i] && flag)Zero_pos = i, flag = false;
				//如果这个0已经越过，且又出现0，则更新0位置下标，以及重新把flag置false
			}
			return flag;
		}
    }
};

inline bool CanJump(vector<int>& nums) {
	int n = nums.size(), Zero_pos = -1;
	for (int i = n - 1; i >= 0; --i) {
		if (!nums[i]) {
			Zero_pos = i;
			break;
		}
	}
	if (Zero_pos < 0)return true;
	else if (!Zero_pos)return n < 2;
	else {
		bool flag = false;
		for (int i = Zero_pos; i >= 0; --i) {
			if (Zero_pos == n - 1 && Zero_pos - i <= nums[i])flag = true;
			else if (Zero_pos - i < nums[i])flag = true;
			if (!nums[i] && flag)Zero_pos = i, flag = false;
		}
		return flag;
	}
	/*
	//本地能过OJ上不行
	static int Step = 0;
	if (Step == nums.size() - 1)return true;
	for (int i = 0; i < nums[Step]; ++i) {
		Step++;
		if (nums[Step])return CanJump(nums);
		Step--;
	}
	return false;
	*/
}

int main(){
	freopen("std.in", "r", stdin);
	vector<int>nums;
	int a;
	while (cin >> a)nums.push_back(a);
	CanJump(nums) ? cout << "true" : cout << "false";
	cout << endl;
	return 0;
}