#define _CRT_SECURE_NO_WARNINGS 1 
#include<cmath>
#include<cstdio>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> Need(rowIndex + 1);
        vector<vector<int>> Triangle(rowIndex + 1);
        for (int i = 0; i <= rowIndex; ++i) {
            Triangle[i].resize(i + 1);
            Triangle[i][0] = Triangle[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                Triangle[i][j] = Triangle[i - 1][j - 1] + Triangle[i - 1][j];
            }
        }
        for (int i = 0; i <= rowIndex; ++i)
            Need[i] = Triangle[rowIndex][i];
        return Need;
    }
};

int main() {

    return 0;
}