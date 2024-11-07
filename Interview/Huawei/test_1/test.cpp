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

class CustStack {
	vector<int>S;
	map<int, int>Count;
	int Max_Count = -1;
	public:
		void Push(vector<int>& S, int x) {
			Count[x]++;
			S.push_back(x);
			Max_Count = max(Max_Count, Count[x]);
			return;
		}
		int Pop(vector<int>& S) {
			if (!S.size())return -1;
			int top = S.size(), x = -1;
			vector<int>Temp;
			while (top--) {
				x = S[top];
				if (Count[x] == Max_Count) {
					Count[x]--, S.pop_back();
					break;
				}
				Temp.push_back(x), S.pop_back();
			}
			if (Temp.size()) {
				for (int i = 0; i < Temp.size(); ++i)
					S.push_back(Temp[i]);
			}
			Max_Count = 0;
			for (int i = 0; i < S.size(); ++i)
				Max_Count = max(Max_Count, Count[S[i]]);
			return x;
		}
};

vector<int>S;
map<int, int>Count;
int Max_Count = -1;
void Push(vector<int>& S, int x) {
	Count[x]++;
	S.push_back(x);
	Max_Count = max(Max_Count, Count[x]);
	return;
}
int Pop(vector<int>& S) {
	if (!S.size())return -1;
	int top = S.size(), x = -1;
	vector<int>Temp;
	while (top--) {
		x = S[top];
		if (Count[x] == Max_Count) {
			Count[x]--, S.pop_back();
			break;
		}
		else Temp.push_back(x), S.pop_back();
	}
	if (Temp.size()) {
		for (int i = 0; i < Temp.size(); ++i)
			S.push_back(Temp[i]);
	}
	Max_Count = 0;
	for (int i = 0; i < S.size(); ++i)
		Max_Count = max(Max_Count, Count[S[i]]);
	return x;
}

int main(){
	freopen("std.in", "r", stdin);
	int a;
	while (cin >> a)Push(S, a);
	int n = S.size();
	for (int i = 0; i <= n; ++i)
		cout << Pop(S) << endl;
	return 0;
}