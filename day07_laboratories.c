#include <stdio.h>
#include <stdlib.h>

typedef char* Line;
typedef unsigned long long ull;

void lswap(Line *l1, Line *l2) {
	Line tmp = *l1;
	*l1 = *l2;
	*l2 = tmp;
}

void cswap(ull* *l1, ull* *l2) {
	ull* tmp = *l1;
	*l1 = *l2;
	*l2 = tmp;
}

#define VIS 0

int main(void) {
	Line cur, next;
	size_t linesz;
	ssize_t width = getline(&cur, &linesz, stdin) - 1;
	ssize_t i;
	ull splits = 0;
	ull *count_cur = calloc(width, sizeof(ull));
	ull *count_next = calloc(width, sizeof(ull));

#if VIS
	printf("%s", cur);
#endif

	while(getline(&next, &linesz, stdin) >= 0) {
		for(i = 0; i < width; ++i)
			(count_cur[i] += (cur[i] == 'S')),
			(cur[i] == 'S' || cur[i] == '|') ? (
				(next[i] == '^') ? (
					(next[i-1] = (next[i+1] = '|')),
					(splits += 1),
					(count_next[i-1] += count_cur[i]),
					(count_next[i+1] += count_cur[i])
				) : (
					(next[i] = '|'),
					(count_next[i] += count_cur[i])
				)
			) : 0;

#if VIS
		printf("%s", next);
#endif
		lswap(&cur, &next);
		cswap(&count_cur, &count_next);
		for(i = 0; i < width; ++i) count_next[i] = 0;;
	}

	ull count = 0;
	for(i = 0; i < width; ++i)
		count += count_cur[i];

	printf("Splits: %llu\n", splits);
	printf("Count: %llu\n", count);
}
