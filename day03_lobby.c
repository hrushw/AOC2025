#include <stdio.h>

unsigned long long maxjoltage(unsigned char *bank, int banksz, unsigned int n) {
	unsigned long long jolt = 0;
	unsigned int n_ = 0, i0 = 0, i;

	while(n_ < n) {
		for(i = i0 + 1; bank[i + (n - n_ - 1)]; ++i)
			if(bank[i] > bank[i0])
				i0 = i;

		jolt = jolt * 10 + (bank[i0] - '0');
		++i0, ++n_;
	}

	return jolt;
}

int main(void) {
	enum {BANKSZ_ = 1024};
	unsigned char bank[BANKSZ_] = {0};
	unsigned long long sum = 0;

	int c;
	unsigned int i = 0;
	while((c = getchar()) != EOF) {
		if(c == '\n') {
			sum += maxjoltage(bank, i, 2);
			i = 0;
			continue;
		}

		bank[i] = c;
		i ++;
	}

	printf("Final Joltage: %llu\n", sum);
	return 0;
}
