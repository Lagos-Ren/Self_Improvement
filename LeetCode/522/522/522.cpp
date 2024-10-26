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
	inline bool cmp(string a, string b) {
		return a.size() < b.size();
	}
	inline int findLUSlength(vector<string>& strs) {
		std::sort(strs.begin(), strs.end(),cmp);

    }
};
/*
bool Cmp(string a, string b) {
	return a.length() < b.length();
}
*/
int main(){
	/*
	vector<string>str;
	string s;
	for (int i = 1; i <= 3; ++i) {
		cin >> s;
		str.push_back(s);
	}
	sort(str.begin(), str.end(), Cmp);
	for (int i = 0; i < 3; ++i)
		cout << str[i] << endl;
	*/
	return 0;
}