#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<iostream>
using namespace std;

double Walk(int n) {
	return (double)n / 1.2;
}

double Bike(int n) {
	return 50.0 + (double)n / 3.0;
}

int main() {
	int n;
	cin >> n;
	double s_1 = Walk(n);
	double s_2 = Bike(n);
	if (s_1 < s_2)cout << "Walk" << endl;
	else if (s_1 > s_2)cout << "Bike" << endl;
	else cout << "All" << endl;
	return 0;
}