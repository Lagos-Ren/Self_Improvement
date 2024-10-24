#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // �����洢���յ��������
        vector<vector<int>> triangle(numRows);

        // ����ÿһ��
        for (int i = 0; i < numRows; ++i) {
            // ÿ�е�Ԫ�ظ���Ϊi+1
            triangle[i].resize(i + 1);
            // ÿ�еĵ�һ�������һ��Ԫ��Ϊ1
            triangle[i][0] = triangle[i][i] = 1;

            // �����м��Ԫ��
            for (int j = 1; j < i; ++j) {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
        return triangle;
    }
};

int main() {
    Solution solution;
    int numRows;
    cin >> numRows;

    vector<vector<int>> result = solution.generate(numRows);

    cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        cout << "[";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}


/*
#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 1145;
int a[N];

int main() {
	int n;
	scanf("numRows = %d", &n);
	for (int i = 1; i <= n; ++i) {
		int l = (i * (i - 1) / 2 + 1), r = (1 + i) * i / 2;
		a[l] = a[r] = 1;
		if (i >= 3) {
			for (int j = l + 1; j <= r - 1; ++j) {
				int delta = j - l, ll = (i - 1) * (i - 2) / 2 + 1;
				a[j] = a[ll + delta - 1] + a[ll + delta];
			}
		}
	}
	cout << "[";
	for (int i = 1; i <= n; ++i) {
		cout << "[";
		int l = (i * (i - 1) / 2 + 1), r = (1 + i) * i / 2;
		if (i == 1)cout << 1;
		else {
			for (int j = l; j <= r; ++j) {
				cout << a[j];
				if (j < r)cout << ",";
			}
		}
		cout << "]";
	}
	cout << "]";
	return 0;
}
*/