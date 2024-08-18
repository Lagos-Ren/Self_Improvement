#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 114514;
char Num[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
char Print[N];

inline void Covert(int n, int B) {
	int a = 0;
	while (n) {
		Print[a++] = Num[n % B];
		n /= B;
	}
	for (int i = a - 1; i >= 0; --i)
		cout << Print[i];
	cout << endl;
	return;
}

int main() {
	int n, b;
	cin >> n >> b;
	Covert(n, b);
	return 0;
}