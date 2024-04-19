#pragma GCC optimize(2)
#include<cmath>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<algorithm>
#define ll long long
#define ull unsigned long long
using namespace std;

inline int qread(){
	int x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*w;
}

inline void qwrite(int x){
	static int sta[35];
	int top=0;
	do{
		sta[top++]=x%10,x/=10;
	}while(x);
	while(top)putchar(sta[--top]+48);
	putchar('\n');
	return;
}

int main(){
	string s;
	ull x;
	cin>>s;
	if(s=="push")cin>>x;
	cout<<s<<" "<<x<<endl;
	
	return 0;
}
