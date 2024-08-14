#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 207;
string S[N], a, b;

int main() {
//  freopen("std.in", "r", stdin);
    int n = 0;
    while (cin >> S[n++]);
    n--;
    b = S[--n];
    a = S[--n];
    for (int i = 0; i < n; ++i) {
        (S[i] == a) ? cout << b : cout << S[i];
        if (i < n - 1)cout << " ";
    }
    return 0;
}
