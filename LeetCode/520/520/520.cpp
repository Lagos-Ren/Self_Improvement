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
	inline bool Judge(char ch) {
		return 'A' <= ch && ch <= 'Z';
	}
    inline bool detectCapitalUse(string word) {
		int len = word.length();
		if (len <= 1)return true;
		else {
			if (Judge(word[0])) {
				if (Judge(word[1])) {
					for (int i = 2; i < len; ++i)
						if (!Judge(word[i]))return false;
				}
				else {
					for (int i = 2; i < len; ++i)
						if (Judge(word[i]))return false;
				}
			}
			else {
				for (int i = 1; i < len; ++i)
					if (Judge(word[i]))return false;
			}
			return true;
		}
    }
};

int main(){
	
	return 0;
}