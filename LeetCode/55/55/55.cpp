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
		int n = nums.size(), Zero_pos = -1;//��¼0��λ��
		for (int i = n - 1; i >= 0; --i) {
			if (!nums[i]) {
				Zero_pos = i;//�ҵ���һ��0����λ�ã��˳�����
				break;
			}
		}
		if (Zero_pos < 0)return true;//���û��0��һ�����Ե����յ�
		else if (!Zero_pos)return n < 2;//���nums[0]=0����ֻ���ж������С�Ƿ�Ϊ1����
		else {//������Ҫ��������
			bool flag = false;//���
			for (int i = Zero_pos; i >= 0; --i) {
				if (Zero_pos == n - 1 && Zero_pos - i <= nums[i])flag = true;
				//���0λ���յ㣬��Ӱ�첻��ֻҪǰ�����ܵ����յ��Ԫ�ؾͿ���
				else if (Zero_pos - i < nums[i])flag = true;
				//�������ҪԽ����ǰ0����λ�ã���ǰ�������Ԫ�ص�ֵ����0�����ľ���
				if (!nums[i] && flag)Zero_pos = i, flag = false;
				//������0�Ѿ�Խ�������ֳ���0�������0λ���±꣬�Լ����°�flag��false
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
	//�����ܹ�OJ�ϲ���
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