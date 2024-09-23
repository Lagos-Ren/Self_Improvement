#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 1e6 + 7;
int n, dp[N];

inline void Init() {
	memset(dp, 0, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= 4; ++i)
		dp[i] = i;
	for (int i = 5; i <= 9; ++i)
		dp[i] = i - 4;
	dp[10] = 2, dp[11] = 1;
	return;
}

int main() {
	Init();
	if (n <= 11)cout << dp[n] << endl;
	else {
		for (int i = 12; i <= n; ++i)
			dp[i] = min(dp[i - 1], min(dp[i - 5], dp[i - 11])) + 1;
		cout << dp[n] << endl;
	}
	return 0;
}

/*
//40pts(WA)
int main() {
	int n;
	cin >> n;
	int ans_5 = n / 5, ans_11 = n / 11;
	int res_5 = n % 5, res_11 = n % 11;
	cout << min(ans_5 + res_5, ans_11 + res_11) << endl;
	return 0;
}
*/