#include <stdio.h>

typedef unsigned long long ull;
int main(void) {
	ull rf, rc, r, rl, ru, sum = 0;

	while(scanf("%llu-%llu,", &rf, &rc) != EOF) {
		for(r = rf; r <= rc; ++r) {
			ull p10 = 1;

			while((rl = (r % p10)) < (ru = (r / p10)))
				p10 *= 10;

			if(rl == ru && (rl / (p10 / 10))) {
				if((sum + r) < sum)
					return fprintf(stderr, "OVERFLOW WARNING!!!\n"), -1;
				sum += r;
				// printf("FOUND: [%llu]\nIn range { %llu - %llu }\nSum evaluates to: %llu\n\n", r, rc, rf, sum);
			}
		}
	}

	printf("Sum evaluates to: %llu\n", sum);
	return 0;
}
