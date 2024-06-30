#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

inline int Days(int n, int m) {
	int date = 1;
	for (int i = 1; i <= m; ++i)
		date = date * n % 7;
	return date;
}

inline string Weekday(int i) {
	switch (i) {
		case 1:return "Monday";
		case 2:return "Tuesday";
		case 3:return "Wednesday";
		case 4:return "Thursday";
		case 5:return "Friday";
		case 6:return "Saturday";
		default:return "Sunday";
	}
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << Weekday(Days(a, b)) << endl;
	return 0;
}