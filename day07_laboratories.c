#include <stdio.h>

typedef char* Line;

void lswap(Line *l1, Line *l2) {
	Line tmp = *l1;
	*l1 = *l2;
	*l2 = tmp;
}

#define VIS 0

int main(void) {
	Line cur, next;
	size_t linesz;
	ssize_t width = getline(&cur, &linesz, stdin) - 1;
	unsigned int splits = 0;

#if VIS
	printf("%s", cur);
#endif

	while(getline(&next, &linesz, stdin) >= 0) {
		for(ssize_t i = 0; i < width; ++i)
			if(cur[i] == 'S' || cur[i] == '|')
				(next[i] == '^') ?
					((next[i-1] = (next[i+1] = '|')), (splits += 1)) :
					(next[i] = '|');

#if VIS
		printf("%s", next);
#endif
		lswap(&cur, &next);
	}

	printf("Splits: %u\n", splits);
}
