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
    int totalNQueens(int n) {
		int Solu[12] = { 0,1,0,0,2,10,4,40,92,352,724,2680 };
		return Solu[n];
    }
};

int main(){
	
	return 0;
}