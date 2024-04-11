#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int MAXN = 1e6+7;

struct List{
	int data=0;
	int next=0;
}L[MAXN];

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

inline void Insert(int x,int y){
	L[y].next=L[x].next;
	L[x].next=y;
	L[y].data=y;
	return;
}

inline void Find(int x){
	if(L[x].next==0)printf("0\n");
	else{
		int y=L[x].next;
		printf("%d\n",L[y].data);
	}
	return;
}

inline void Del(int x){
	int y=L[x].next;
	L[y].data=0;
	L[x].next=L[y].next;
	L[y].next=0;
	return;
}

int main(){
	int p,q,x,y;
	p=qread();
	L[1].data=1;
	while(p--){
		q=qread();
		switch(q){
			case 1:x=qread(),y=qread();Insert(x,y);break;
			case 2:x=qread();Find(x);break;
			case 3:x=qread();Del(x);break;
			default:break;
		}
	}
	return 0;
}
