#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 30;
struct Str {
	char str[N];
	int len;
};
Str a, b;

inline bool Judge() {
	bool flag = false;
	for (int i = 0; i < b.len; ++i) {
		if (b.str[i] == a.str[0]) {
			int j, k;
			for (j = 0, k = i; j < a.len; ++j, ++k)
				if (a.str[j] != b.str[k])break;
			if (j == a.len)flag = true;
		}
	}
	return flag;
}

int main() {
	cin >> a.str >> b.str;
	a.len = strlen(a.str), b.len = strlen(b.str);
	if (a.len > b.len)swap(a, b);
	if (Judge())cout << a.str << " is substring of " << b.str;
	else cout << "No substring";
	return 0;
}