#define _CRT_SECURE_NO_WARNINGS 1 
#include<map>
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
    int lengthOfLongestSubstring(string s) {
		int n = s.length();
		if (!n)return 0;
		else if (n == 1)return 1;
		int Max_len = 0;
		for (int i = 0; i < n; ++i) {
			int len = 0;
			map<char, bool>m;
			for (int j = i; j < n; ++j) {
				if (!m[s[j]])m[s[j]] = true, len++;
				else break;
			}
			Max_len = max(Max_len, len);
		}
		return Max_len;
    }
};

int main(){
	
	return 0;
}