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
    bool Is_Type(char ch) {
        return ('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z');
    }
    int lengthOfLastWord(string s) {
        int n = s.length();
        if (!n)return 0;
        if (n == 1)return (int)Is_Type(s[0]);
        int i = n;
        while (i--) {
            if (Is_Type(s[i]))break;
        }
        int len = 0;
        for (int j = i; j >= 0; --j) {
            if (Is_Type(s[j]))len++;
            else break;
        }
        return len;
    }
};

bool Is_Type(char ch) {
    return ('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z');
}
int lengthOfLastWord(string s) {
    int n = s.length();
    if (!n)return 0;
    if (n == 1)return (int)Is_Type(s[0]);
    int i = n;
    while (i--) {
        if (Is_Type(s[i]))break;
    }
    int len = 0;
    for (int j = i; j >= 0; --j) {
        if (Is_Type(s[j]))len++;
        else break;
    }
    return len;
}

int main(){
    string s = "Hello World";
    cout << lengthOfLastWord(s) << endl;
	return 0;
}