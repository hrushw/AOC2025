#include <stdio.h>

enum { MAXLINES_ = 16 };
int part1(char* lines[], char* shlines[], int nlines) {
	unsigned long long total = 0;
	unsigned long long ans = 0;
	unsigned int num = 0;
	unsigned int i;

	int off = 0;
	char op = 0;
	while(sscanf(shlines[nlines], "%c %n", &op, &off) != EOF) {
		shlines[nlines] += off;

		ans = (op == '*');
		for(i = 0; i < nlines; ++i) {
			sscanf(shlines[i], "%u %n", &num, &off);
			ans = ((op == '*') ? (ans * num) : (ans + num));
			shlines[i] += off;
		}

		if(total + ans < total)
			return fprintf(stderr, "Error: Integer overflow!\n"), -1;
		total += ans;
	}

	printf("Total: %llu\n", total);
	return 0;
}

int getvnum(char* shlines[], unsigned int *n, int nlines) {
	unsigned int i;
	*n = 0;
	int ret = -1;

	for(i = 0; i < nlines; ++i) {
		if('0' <= shlines[i][0] && shlines[i][0] <= '9') {
			*n = ((*n) * 10) + (shlines[i][0] - '0');
			ret = 0;
		}
		shlines[i] += 1;
	}

	return ret;
}

int part2(char* lines[], char* shlines[], int nlines) {
	unsigned long long total = 0;
	unsigned long long ans = 0;
	unsigned int num = 0;
	unsigned int i;

	int off = 0;
	char op = 0;
	while(sscanf(shlines[nlines], "%c %n", &op, &off) != EOF) {
		shlines[nlines] += off;
		ans = (op == '*');

		while(!getvnum(shlines, &num, nlines))
			ans = ((op == '*') ? (ans * num) : (ans + num));

		if(total + ans < total)
			return fprintf(stderr, "Error: Integer overflow!\n"), -1;
		total += ans;
	}

	printf("Total: %llu\n", total);
	return 0;
}

int main(void) {
	int nlines = 0;
	char* lines[MAXLINES_] = {0};
	char* shlines[MAXLINES_] = {0};

	size_t linesz = 0;
	while(getline(&lines[nlines], &linesz, stdin) != -1) {
		shlines[nlines] = lines[nlines];
		nlines += 1;

		if(nlines >= MAXLINES_)
			return fprintf(stderr, "Error: too many lines!\n"), -1;
	}
	nlines -= 1;

	return part2(lines, shlines, nlines);
}
