#include <stdio.h>
#include <unistd.h>

int part1(void) {
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

int truemod(int a, int b) {
	return a > 0 ? a % b : b - (- a) % b;
}

int abstruequot(int a, int b) {
	return a > 0 ? a / b : ((-a / b) + 1);
}

int part2(void) {
	char dirn = '0';
	unsigned int dist = 0;
	int pos = 50;
	unsigned int pwd = 0;
	while(scanf("%c%u\n", &dirn, &dist) != EOF) {
		if(dirn == 'L') {
			while(dist) {
				-- pos;
				if(!pos) pwd += 1;
				else if(pos < 0) pos += 100;
				dist --;
			}
		} else if(dirn == 'R') {
			while(dist) {
				++pos;
				pos %= 100;
				if(!pos) pwd += 1;
				dist --;
			}
		} else
			return fprintf(stderr, "ERROR: Invalid direction '0x%u'\n", dirn), -1;
	}

	printf("Password evaluates to: %u\n", pwd);

	return 0;
}

int main(void) {
	return part2();
}
