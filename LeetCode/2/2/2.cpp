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

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		vector<int>nums1, nums2;
		for (; l1; l1 = l1->next)nums1.push_back(l1->val);
		for (; l2; l2 = l2->next)nums2.push_back(l2->val);
		int len = max(nums1.size(), nums2.size());
		vector<int>ans;


	}
};

/*
class Solution {
public:
	void Insert(ListNode *L,int val) {
		ListNode* T = (ListNode*)malloc(sizeof(ListNode*));
		T->val = val;
		T->next = NULL;
		L->next = T;
		return;
	}
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* L = (ListNode*)malloc(sizeof(ListNode*));
		bool flag = false;
		for (; l1 != NULL && l2 != NULL; l1 = l1->next, l2 = l2->next) {
			int u = l1->val, v = l2->val;
			int ans = u + v;
			if (flag)ans++, flag = false;
			if (ans > 9)flag = true, ans -= 10;
			Insert(L, ans);
		}
		return L;
	}
};
*/

int main(){
	
	return 0;
}