#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    string input;
    while (getline(cin, input)) {
        stringstream ss(input);//stringstream·Ö¸î×Ö·û´®
        string temp;
        vector<string>str;//¶¯Ì¬´æ´¢µ¥´Ê
        while (getline(ss, temp, ','))
            str.push_back(temp);//°´¶ººÅ·Ö¸î×Ö·û´®
        sort(str.begin(), str.end());//ÅÅÐò
        for (int i = 0; i < str.size(); ++i) {
            if (i < str.size() - 1)cout << str[i] << ",";
            else cout << str[i] << endl;
        }
    }
    return 0;
}

/*
//2
int main() {
    string input;
    while (getline(cin, input)) {
        stringstream ss(input);//stringstream·Ö¸î×Ö·û´®
        string temp;
        vector<string>str;//¶¯Ì¬´æ´¢µ¥´Ê
        while (ss >> temp)
            str.push_back(temp);//°´¿Õ¸ñ·Ö¸î×Ö·û´®
        sort(str.begin(), str.end());//ÅÅÐò
        for (int i = 0; i < str.size(); ++i) {
            if (i < str.size() - 1)cout << str[i] << " ";
            else cout << str[i] << endl;
        }
    }
    return 0;
}
*/

/*
//1
const int N = 105;
int n;
string s[N];

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> s[i];
	sort(s + 1, s + 1 + n);
	for (int i = 1; i <= n; ++i) {
		if (i < n)cout << s[i] << " ";
		else cout << s[i] << endl;
	}
	return 0;
}
*/