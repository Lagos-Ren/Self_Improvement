#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int n, k;

inline void Work() {
	if (n == 1) {
		for (int i = 1; i <= k; ++i)
			cout << i << endl;
		return;
	}
	else if (n == 2) {
		for (int i = 1; i <= k; ++i)
			for (int j = 1; j <= k; ++j)
				cout << i << " " << j << endl;
		return;
	}
	else if (n == 3) {
		for (int i = 1; i <= k; ++i)
			for (int j = 1; j <= k; ++j)
				for (int l = 1; l <= k; ++l)
					cout << i << " " << j << " " << l << endl;
		return;
	}
	else if (n == 4) {
		for (int i = 1; i <= k; ++i)
			for (int j = 1; j <= k; ++j)
				for (int l = 1; l <= k; ++l)
					for (int m = 1; m <= k; ++m)
						cout << i << " " << j << " " << l << " " << m << endl;
		return;
	}
	else if (n == 5) {
		for (int i = 1; i <= k; ++i)
			for (int j = 1; j <= k; ++j)
				for (int l = 1; l <= k; ++l)
					for (int m = 1; m <= k; ++m)
						for (int o = 1; o <= k; ++o)
							cout << i << " " << j << " " << l << " " << m << " " << o << endl;
		return;
	}
	return;
}

int main() {
	cin >> n >> k;
	Work();
	return 0;
}
