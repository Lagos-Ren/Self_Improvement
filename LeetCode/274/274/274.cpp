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
    int hIndex(vector<int>& citations) {
		sort(citations.begin(), citations.end());
		int Crr = -1, n = citations.size(), h = -1;
		for (int i = 0; i < n; ++i) {
			if (citations[i] != Crr) {
				Crr = citations[i];
				h = max(h, min(Crr, n - i));
			}
		}
		return h;
    }
};

int main(){
	
	return 0;
}