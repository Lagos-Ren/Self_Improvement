#include<iostream>
using namespace std;

int main() {
	double A = 10000.0, B = 10000.0;
	for (int i = 1; i <= 5; ++i)
		A = A * 1.035;
	B = B * 1.2;
	cout << A << " " << B << endl;
	return 0;
}