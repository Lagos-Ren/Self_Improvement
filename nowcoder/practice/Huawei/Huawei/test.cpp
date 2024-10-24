//https://www.nowcoder.com/exam/test/1088888/summary
#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

//T3
inline int Trans(char ch) {
	if ('0' <= ch && ch <= '9')return int(ch - '0');
	else if ('A' <= ch && ch <= 'F')return int(ch - 'A') + 10;
	else return -1;
}

int main() {
	string s;
	cin >> s;
	int len = s.length(), num = 0;
	for (int i = len - 1; i >= 0; --i) {
		if (Trans(s[i]) < 0)break;
		else num += Trans(s[i]) * pow(16, len - i - 1);
	}
	cout << num << endl;
	return 0;
}

/*
//T2
const int N = 1005;
int n, Print[N];
bool flag[N];

int main() {
	cin >> n;
	int val, m = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> val;
		if (!flag[val])flag[val] = true, Print[m++] = val;
	}
	sort(Print, Print + m);
	for (int i = 0; i < m; ++i)
		cout << Print[i] << endl;
	return 0;
}
*/

/*
//T1
int main() {
	int n;
	while (cin >> n) {
		if (!n)break;
		int x = 0, y = n, z = 0;
		while (y >= 3) {
			x = y / 3;
			y %= 3;
			y += x;
			z += x;
		}
		if (y >= 2)z++;
		cout << z << endl;
	}
	return 0;
}
*/