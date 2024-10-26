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
    int findLUSlength(string a, string b) {
		if (a == b)return -1;
		else return max(a.length(), b.length());
    }
};

int main(){
	
	return 0;
}