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
		int carry = 0;  // ��λ
		ListNode* dummy = new ListNode(0);  // ����ͷ�ڵ㣬�򻯴���
		ListNode* current = dummy;
		while (l1 != nullptr || l2 != nullptr || carry != 0) {
			int temp = carry;  // ��ʼ��tempΪcarry����ʾ��λ
			if (l1) {
				temp += l1->val;
				l1 = l1->next;
			}
			if (l2) {
				temp += l2->val;
				l2 = l2->next;
			}
			carry = temp / 10;  // �����λ
			current->next = new ListNode(temp % 10);  // �����½ڵ�
			current = current->next;
		}
		return dummy->next;  // ���ؽ��������������ͷ�ڵ�
	}
};

/*
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		vector<int>ans;
		int temp = 0;
		bool flag = false;
		while (l1 || l2) {
			if (l1)temp += l1->val, l1 = l1->next;
			if (l2)temp += l2->val, l2 = l2->next;
			if (flag)temp++, flag = false;
			if (temp > 9)temp -= 10, flag = true;
			ans.push_back(temp);
		}
		if (flag)ans.push_back(1);
		ListNode* Ans = (ListNode*)malloc(sizeof(ListNode*));
		Ans->val = ans[0], Ans->next = NULL;
		ListNode* p = Ans;
		for (int i = 1; i < ans.size(); ++i) {
			ListNode* v = (ListNode*)malloc(sizeof(ListNode*));
			v->val = ans[i];
			v->next = NULL;
			p->next = v;
			p = v;
		}
		return Ans;
	}
};
*/

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