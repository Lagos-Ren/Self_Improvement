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

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	vector<int>Value;
	bool f[100005], flag = false;
	void DFSTraversal(TreeNode* root) {
		if (root == NULL)return;
		DFSTraversal(root->left);
		if (!f[root->val]) {
			f[root->val] = true;
			Value.push_back(root->val);
		}
		else flag = true;
		DFSTraversal(root->right);
		return;
	}
    int getMinimumDifference(TreeNode* root) {
		memset(f, false, sizeof(false));
		DFSTraversal(root);
		if (flag)return 0;
		else {
			sort(Value.begin(), Value.end());
			int Mininum = 0x7fffffff;
			for (int i = 1; i < Value.size(); ++i) {
				Mininum = min(Mininum, Value[i] - Value[i - 1]);
			}
			return Mininum;
		}
    }
};

int main(){
	
	return 0;
}