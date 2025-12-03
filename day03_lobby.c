#include <stdio.h>

int maxjoltage_2(unsigned char *bank, int banksz) {
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

unsigned long long maxjoltage(unsigned char *bank, int banksz, unsigned int n) {
	unsigned long long jolt = 0;

	unsigned int n_ = 0;
	unsigned int i0 = 0, i;

	while(n_ < n) {
		for(i = i0 + 1; bank[i + (n - n_ - 1)]; ++i)
			if(bank[i] > bank[i0])
				i0 = i;

		jolt *= 10;
		jolt += (bank[i0] - '0');

		i0 += 1;
		n_ += 1;
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
			sum += maxjoltage(bank, i, 12);
			i = 0;
			continue;
		}

		bank[i] = c;
		i ++;
	}

	printf("Final Joltage: %llu\n", sum);
	return 0;
}
