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
    bool isValid(string s) {
		vector<char>chs;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')chs.push_back(s[i]);
			else if (s[i] == ')') {
				if (!chs.size())return false;
				if (chs[chs.size() - 1] == '(')chs.pop_back();
				else return false;
			}
			else if (s[i] == ']') {
				if (!chs.size())return false;
				if (chs[chs.size() - 1] == '[')chs.pop_back();
				else return false;
			}
			else if (s[i] == '}') {
				if (!chs.size())return false;
				if (chs[chs.size() - 1] == '{')chs.pop_back();
				else return false;
			}
			else return false;
		}
		return !chs.size();
    }
};

int main(){
	
	return 0;
}