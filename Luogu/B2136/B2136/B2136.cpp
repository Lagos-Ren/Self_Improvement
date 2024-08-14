#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;

const int N = 10086;
int Prime[N];

inline bool is_Prime(int n) {
	if (n == 0 || n == 1)return false;
	if (n == 2 || n == 3)return true;
	if (!(n % 2))return false;
	for (int i = 3; i <= sqrt(n); i += 2)
		if (!(n % i))return false;
	return true;
}

int main() {
	int n, m = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		if (is_Prime(i))Prime[++m] = i;
	int len, num[10], tot = 0;
	for (int i = 1; i <= m; ++i) {
		int tem = Prime[i];
		if (tem < 10)continue;
		len = 0;
		memset(num, 0, sizeof(num));
		while (tem)num[++len] = tem % 10, tem /= 10;
		bool flag = true;
		for(int j=1;j<=len/2;++j)
			if (num[j] != num[len - j + 1]) { flag = false; break; }
		if (flag)tot++;
	}
	cout << tot << endl;
	return 0;
}