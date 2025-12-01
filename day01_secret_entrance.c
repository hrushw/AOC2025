#include <stdio.h>

const int part = 1;
int main(void) {
	char dirn = '0';
	unsigned int dist = 0;
	int pos = 50;
	unsigned int pwd = 0;

	while(scanf("%c%u\n", &dirn, &dist) != EOF) {
		pos = (dirn == 'L' ? (100 - pos) % 100 : pos);
		if(part == 2) pwd += ((pos + dist) / 100);
		pos = ((pos + dist) % 100);
		if(part == 1) pwd += !pos;
		pos = (dirn == 'L' ? (100 - pos) % 100 : pos);
	}

	printf("Password evaluates to: %u\n", pwd);
	return 0;
}
