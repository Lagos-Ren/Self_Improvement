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
	bool digitCount(string num) {
		int len = num.length();
		for (int i = 0; i < len; ++i) {
			char Current_num = i + 48, Times = '0';
			for (int j = 0; j < len; ++j)
				if (num[j] == Current_num)Times++;
			if (Times != num[i])return false;
		}
		return true;
	}
};

int main(){
	
	return 0;
}