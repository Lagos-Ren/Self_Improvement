#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

inline bool is_Odd(int i) {
	return !(i % 2) ? false : true;
}

inline void JiaoGu(int i) {//TLE 80pts
	if (i == 1) {
		cout << "End" << endl;
		return;
	}
	if (is_Odd(i)) {
		int j = i * 3 + 1;
		cout << i << "*3+1=" << j << endl;
		JiaoGu(j);
	}
	else {
		int j = i / 2;
		cout << i << "/2=" << j << endl;
		JiaoGu(j);
	}
	return;
}

int main() {
	long long n, m;
	cin >> n;
//	JiaoGu(n);
	while (n != 1) {
		m = n;
		if (is_Odd(m)) {
			n = n * 3 + 1;
			cout << m << "*3+1=" << n << endl;
		}
		else {
			n = n / 2;
			cout << m << "/2=" << n << endl;
		}

	}
	cout << "End" << endl;
	return 0;
}