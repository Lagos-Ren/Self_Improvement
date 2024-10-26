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
	inline bool Judge(int n) {
		int m = n, a = n % 10;
		while (n) {
			if (!a)return false;
			else if (m % a)return false;
			n /= 10;
			a = n % 10;
		}
		return true;
	}
	inline vector<int> selfDividingNumbers(int left, int right) {
		vector<int>Self;
		for (int i = left; i <= right; ++i)
			if (Judge(i))Self.push_back(i);
		return Self;
    }
};

int main(){
	
	return 0;
}