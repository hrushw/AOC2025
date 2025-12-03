#include <stdio.h>

int maxjoltage(unsigned char *bank, int banksz) {
	unsigned int i1 = 0, i0, i;

	for(i = 1; bank[i+1]; ++i)
		if(bank[i] > bank[i1])
			i1 = i;

	i0 = i1 + 1;
	for(i = i1+2; bank[i]; ++i)
		if(bank[i] > bank[i0])
			i0 = i;

	return (((bank[i1] - '0') * 10) + (bank[i0] - '0'));
}

int main(void) {
	enum {BANKSZ_ = 1024};
	unsigned char bank[BANKSZ_] = {0};
	unsigned long sum = 0;

	int c;
	unsigned int i = 0;
	while((c = getchar()) != EOF) {
		if(c == '\n') {
			sum += maxjoltage(bank, i);
			i = 0;
			continue;
		}

		bank[i] = c;
		i ++;
	}

	printf("Final Joltage: %lu\n", sum);
	return 0;
}
