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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if (n < 2)return gas[0] >= cost[0] ? 0 : -1;
        vector<int>Diff(n);
        vector<int>Maxi;
        for (int i = 0; i < n; ++i) {
            Diff[i] = gas[i] - cost[i];
            if (Diff[i] > 0)Maxi.push_back(i);
        }
        int m = Maxi.size();
        if (!m)return -1;
        sort(Maxi.begin(), Maxi.end());
        for (int k = 0; k < m; ++k) {
            int i = Maxi[k];
            int Con = Diff[i];
            int j = (i == n - 1 ? 0 : i + 1);
            bool flag = true;
            for (; flag; ++j) {
                if (j == n)j = 0;
                if (j == i)break;
                Con += Diff[j];
                if (Con <= 0 && j != (!i ? n - 1 : i - 1))flag = false;
            }
            if (Con < 0)flag = false;
            if (!flag)continue;
            else return i;
        }
        return -1;
    }
};

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    cout << "n=" << n << endl;
    if (n < 2)return gas[0] >= cost[0] ? 0 : -1;
    vector<int>Diff(n);
    vector<int>Maxi;
    for (int i = 0; i < n; ++i) {
        Diff[i] = gas[i] - cost[i];
        cout << Diff[i] << " ";
        if (Diff[i] > 0)Maxi.push_back(i);
    }
    cout << endl;
    int m = Maxi.size();
    if (!m)return -1;
    sort(Maxi.begin(), Maxi.end());
    for (int i = 0; i < m; ++i)
        cout << Maxi[i] << " ";
    cout << endl;
    for (int k = 0; k < m; ++k) {
        int i = Maxi[k];
        int Con = Diff[i];
        int j = (i == n - 1 ? 0 : i + 1);
        cout << "i=" << i << ",Con=" << Con << ",j=" << j << endl;
        bool flag = true;
        for (; flag; ++j) {
            if (j == n)j = 0;
            if (j == i)break;
            Con += Diff[j];
            if (Con <= 0 && j != (!i ? n - 1 : i - 1))flag = false;
        }
        if (Con < 0)flag = false;
        if (!flag)continue;
        else return i;
    }
    return -1;
}

int main(){
    freopen("std.in", "r", stdin);
    int n, a;
    vector<int>gas, cost;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        gas.push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        cin >> a;
        cost.push_back(a);
    }
    cout << canCompleteCircuit(gas, cost) << endl;
	return 0;
}