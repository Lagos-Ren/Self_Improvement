#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1145;
char s[N];
int Print[N];

inline int Power(int n, int p) {
	if (!p)return 1;
	int ans = 1;
	for (int i = 1; i <= p; ++i)
		ans *= n;
	return ans;
}

int main() {
	scanf("%s", s);
	int len = strlen(s), k = 0;
	reverse(s, s + len);
	for (int i = 0; i < len; i += 4) {
		int j, Dnum = 0;
		for (j = 0; j < 4; ++j) {
			if (s[i + j] < '0' || s[i + j]>'8')
				s[i + j] = '0';
			Dnum += (s[i + j] - '0') * Power(8, j);
		}
		Print[k++] = Dnum;
	}
	for (int i = k - 1; i >= 0; --i) {
		if (i < k - 1)printf("%03x", Print[i]);
		else printf("%x", Print[i]);
	}
	return 0;
}