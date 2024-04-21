#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

const int MAXN = 1e5 + 7;
int que[MAXN];
int front = 0, rear = 0;

inline void Push(int x) {
	que[rear++] = x;
	return;
}

inline void Pop() {
	if (front >= rear) {
		printf("ERR_CANNOT_POP\n");
		return;
	}
	front++;
	return;
}

inline void Query() {
	if (front >= rear) {
		printf("ERR_CANNOT_QUERY\n");
		return;
	}
	printf("%d\n",que[front]);
	return;
}

inline void Size() {
	printf("%d\n", rear - front);
	return;
}

int main() {
	int n,opt,x;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &opt);
		if (opt == 1) {
			scanf("%d", &x);
			Push(x);
		}
		else if (opt == 2) Pop();
		else if (opt == 3) Query();
		else if (opt == 4) Size();
	}
	return 0;
}