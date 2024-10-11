#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

inline bool Judge(int n) {
	int m = n, a = n % 10;
	n /= 10;
	int b = n % 10;
	n /= 10;
	int c = n;
	return (pow(a, 3) + pow(b, 3) + pow(c, 3) == m) ? true : false;
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		bool flag = false;
		for (int i = n; i <= m; ++i)
			if (Judge(i)) {
				flag = true;
				cout << i << " ";
			}
		if (!flag)cout << "no";
		cout << endl;
	}
	return 0;
}

/*
int main() {
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF) {
		double num = (double)n, ans = 0.0;
		for (int i = 1; i <= m; ++i)
			ans += num, num = sqrt(num);
		printf("%.2lf\n", ans);
	}
	return 0;
}
*/