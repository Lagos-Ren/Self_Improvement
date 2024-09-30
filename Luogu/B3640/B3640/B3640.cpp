#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1005;
string Print[N];

inline bool is_Num(char ch) {
	return (ch >= '0' && ch <= '9');
}

inline bool is_Ch(char ch) {
	return (ch >= 'A' && ch <= 'Z');
}

inline void Oper(string& s) {
	if (is_Num(s[0]))reverse(s.begin(), s.end());
	else if (is_Ch(s[0])) {
		for (int i = 0; i <= s.size(); ++i)
			s[i] += 32;
	}
	else {
		for (int i = 0; i <= s.size(); ++i)
			s[i] -= 32;
	}
	return;
}

int main() {
//	freopen("Std.in", "r", stdin);
	int n = 0;
	string s;
	while (cin >> s)Print[++n] = s;
	for (int i = 1; i <= n; ++i)
		Oper(Print[i]);
	for (int i = n; i >= 1; --i) {
		if (i > 1)cout << Print[i] << " ";
		else cout << Print[i] << endl;
	}
	return 0;
}