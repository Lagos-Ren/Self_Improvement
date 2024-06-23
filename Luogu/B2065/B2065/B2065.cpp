#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define ST 0.05
using namespace std;

const int N = 25;
struct Node {
	int x, y;
	double rt;
}Sample[N];
int n;

double Rate_Cul(int x, int y) {
	return (double)y / (double)x;
}

int Comp(double x, double y) {
	if (abs(x - y) <= ST)return 0;
	else if (x - y > ST)return 1;
	else return -1;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> Sample[i].x >> Sample[i].y;
		Sample[i].rt = Rate_Cul(Sample[i].x, Sample[i].y);
	}
	for (int i = 1; i < n; ++i) {
		if (!Comp(Sample[0].rt, Sample[i].rt))cout << "same" << endl;
		else {
			if (Comp(Sample[0].rt, Sample[i].rt) > 0)cout << "worse" << endl;
			else if (Comp(Sample[0].rt, Sample[i].rt) < 0)cout << "better" << endl;
		}
	}
	return 0;
}