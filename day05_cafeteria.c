#include <stdio.h>

typedef unsigned long long ull;

int main(void) {
	enum { MAXRANGES_ = 1024 };
	static ull ranges[MAXRANGES_][2];
	static unsigned char marks[MAXRANGES_] = {0};
	unsigned int nranges = 0;
	unsigned int i, j;
	unsigned int sum = 0;
	ull total=0;

	while(scanf("%llu-%llu", &ranges[nranges][0], &ranges[nranges][1]) == 2) {
		++nranges;
		if(nranges >= MAXRANGES_)
			return fprintf(stderr, "Error: Too many ranges!\n"), -1;
	}

	ull n = ranges[nranges][0];
	do for(i = 0; i < nranges; ++i)
		if(ranges[i][0] <= n && ranges[i][1] >= n) {
			sum += 1;
			break;
		}
	while(scanf("%llu", &n) == 1);

	for(i = 0; i < nranges; ++i) {
		for(j = i+1; j < nranges; ++j) {
			if(marks[j]) continue;
			if(ranges[j][0] <= ranges[i][1] && ranges[j][1] >= ranges[i][1]) {
				ranges[i][1] = ranges[j][1];
				marks[j] = 1;
			}
			if(ranges[j][0] <= ranges[i][0] && ranges[j][1] >= ranges[i][0]) {
				ranges[i][0] = ranges[j][0];
				marks[j] = 1;
			}
			if(ranges[j][0] >= ranges[i][0] && ranges[j][1] <= ranges[i][1])
				marks[j] = 1;
			if(marks[j])
				j = i;
		}
	}

	for(i = 0; i < nranges; ++i)
		if(!marks[i])
			total += (1 + (ranges[i][1] - ranges[i][0]));

	printf("Found: [%u] fresh ingredients\n", sum);
	printf("Total: [%llu] possible fresh ingredients\n", total);
	return 0;
}
