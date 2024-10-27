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
    int removeElement(vector<int>& nums, int val) {
		if (!nums.size())return 0;
		sort(nums.begin(), nums.end());
		int l = -1, r = -1, n = nums.size();
		if (nums[0] == val)l = 0;
		else {
			for (int i = 1; i < n; ++i) {
				if (nums[i - 1] != val && nums[i] == val)l = i;
			}
		}
		if (nums[n - 1] == val)r = n - 1;
		else {
			for (int i = 0; i < n - 1; ++i) {
				if (nums[i] == val && nums[i + 1] != val)r = i;
			}
		}
		if (l < 0 && r < 0)return n;
		else {
			int k = n - (r - l + 1), Delta = n - r - 1;
			for (int i = l, j = n - 1; i <= r && j > r; ++i, --j)
				swap(nums[i], nums[j]);
			return k;
		}
    }
};

int main(){
	freopen("std.in", "r", stdin);
	vector<int>nums;
	int val;
	cin >> val;
	int a;
	while (cin >> a)nums.push_back(a);
	if (!nums.size())cout << 0 << endl;
	else {
		sort(nums.begin(), nums.end());
		int l = -1, r = -1, n = nums.size();
		if (nums[0] == val)l = 0;
		else {
			for (int i = 1; i < n; ++i) {
				if (nums[i - 1] != val && nums[i] == val)l = i;
			}
		}
		if (nums[n - 1] == val)r = n - 1;
		else {
			for (int i = 0; i < n - 1; ++i) {
				if (nums[i] == val && nums[i + 1] != val)r = i;
			}
		}
		cout << l << " " << r << endl;
		if (l < 0 && r < 0)cout << 0 << endl;
		else {
			int k = n - (r - l + 1), Delta = n - r - 1;
			for (int i = l, j = n - 1; i <= r && j > r; ++i, --j)
				swap(nums[i], nums[j]);
			cout << k << " " << Delta << endl;
		}
		for (int i = 0; i < n; ++i)
			cout << nums[i] << " ";
		cout << endl;
	}
	return 0;
}