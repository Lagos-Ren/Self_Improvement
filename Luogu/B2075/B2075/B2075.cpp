#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int ans = 1;
	for (int i = 1; i <= b; ++i) {
		ans *= a;
		ans %= 10000;
	}
	if (ans < 10)cout << "00" << ans << endl;
	else if (ans < 100)cout << "0" << ans << endl;
	else cout << ans % 1000 << endl;
	return 0;
}