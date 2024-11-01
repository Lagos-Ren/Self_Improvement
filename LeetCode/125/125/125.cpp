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
	char Convert(char ch) {
		return ('a' <= ch && ch <= 'z') ? ch : ch + 32;
	}
	bool isType(char ch) {
		return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z');
	}
	bool isNum(char ch) {
		return ('0' <= ch && ch <= '9');
	}
	bool isPalindrome(string s) {
		vector<char>chs;
		for (int i = 0; i < s.length(); ++i) {
			if (isType(s[i]))chs.push_back(Convert(s[i]));
			else if (isNum(s[i]))chs.push_back(s[i]);
		}
		int l = 0, r = chs.size() - 1;
		while (l < r) {
			if (chs[l++] != chs[r--])return false;
		}
		return true;
	}
};

char Convert(char ch) {
	return ('a' <= ch && ch <= 'z') ? ch : ch + 32;
}
bool isType(char ch) {
	return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z');
}
bool isNum(char ch) {
	return ('0' <= ch && ch <= '9');
}
bool isPalindrome(string s) {
	vector<char>chs;
	for (int i = 0; i < s.length(); ++i) {
		if (isType(s[i]))chs.push_back(Convert(s[i]));
		else if (isNum(s[i]))chs.push_back(s[i]);
	}
	int l = 0, r = chs.size() - 1;
	while (l < r) {
		if (chs[l++] != chs[r--])return false;
	}
	return true;
}

int main(){
	string s;
	cin >> s;
	cout << isPalindrome(s) << endl;
	return 0;
}