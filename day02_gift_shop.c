#include <stdio.h>

typedef unsigned long long ull;


int part1(void) {
	ull rf, rc, r, rl, ru, sum = 0;

	while(scanf("%llu-%llu,", &rf, &rc) != EOF) {
		ull p10 = 1;
		while((p10 - 1) < (ru = (rf / p10))) p10 *= 10;
		for(rl = (p10 / 10); rl < p10; ++rl) {
			r = rl * (p10 + 1);
			if(r >= rf && r <= rc) sum += r;
		}
	}

	printf("Sum evaluates to: %llu\n", sum);
	return 0;
}

int part2(void) {
	ull rf, rc, r, rl, ru, sum = 0, p10;

	while(scanf("%llu-%llu,", &rf, &rc) != EOF)
		for(r = rf; r <= rc; ++r)
			for(p10 = 10; p10 < r; p10 *= 10) {
				rl = r % p10;
				ru = r / p10;

				if(!(rl / (p10 / 10))) continue;
				while((ru % p10) == rl) ru /= p10;
				if(ru) continue;

				sum += r;
				break;
			}

	printf("Sum evaluates to: %llu\n", sum);
	return 0;
}

int main(void) {
	return part2();
}
