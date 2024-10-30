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
	vector<string>strs;
	string s;
	void DFS(int n, int i) {
		if (i == n) {
			strs.push_back(s);
			return;
		}
		if (!i || s[i - 1] != '0') {
			s.push_back('0');
			DFS(n, i + 1);
			s.pop_back();
		}
		s.push_back('1');
		DFS(n, i + 1);
		s.pop_back();
		return;
	}
	vector<string> validStrings(int n) {
		DFS(n, 0);
		return strs;
	}
};

vector<string>strs;
string s;

void DFS(int n, int i) {
	if (i == n) {
		strs.push_back(s);
		return;
	}
	if (!i|| s[i - 1] != '0') {
		s.push_back('0');
		DFS(n, i + 1);
		s.pop_back();
	}
	s.push_back('1');
	DFS(n, i + 1);
	s.pop_back();
	return;
}
vector<string> validStrings(int n) {
	DFS(n, 0);
	return strs;
}

int main(){
	int n;
	cin >> n;
	vector<string>Str = validStrings(n);
	for (int i = 0; i < Str.size(); ++i)
		cout << Str[i] << endl;
	return 0;
}