#include <stdio.h>
#include <unistd.h>

int main(void) {
	char dirn = '0';
	unsigned int dist = 0;
	int pos = 50;
	unsigned int pwd = 0;

	while(scanf("%c%u\n", &dirn, &dist) != EOF) {
		if(dirn == 'L')
			pos -= (dist % 100);
		else if(dirn == 'R')
			pos += (dist % 100);
		else
			return fprintf(stderr, "ERROR: Invalid direction '0x%u'\n", dirn), -1;

		while(pos < 0) pos += 100;
		pos %= 100;

		if(pos == 0) pwd += 1;
	}

	printf("Password evaluates to: %u\n", pwd);
	return 0;
}
