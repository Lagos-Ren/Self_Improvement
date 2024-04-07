#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>

int main() {
	int candy[6] = { 0 },eat=0;
	for (int i = 1; i <= 5; ++i)
		scanf("%d", &candy[i]);
	for (int i = 1; i <= 5; ++i) {
		int l = i - 1, r = i + 1, mod, alloc;
		if (l < 1)l = 5;
		if (r > 5)r = 1;
		mod = candy[i] % 3, alloc = candy[i] / 3;
		eat += mod;
		candy[l] += alloc, candy[r] += alloc, candy[i] = alloc;
	}
	for (int i = 1; i < 5; ++i)
		printf("%d ", candy[i]);
	printf("%d\n%d\n", candy[5], eat);
	return 0;
}