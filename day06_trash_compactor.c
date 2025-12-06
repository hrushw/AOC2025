#include <stdio.h>

int main(void) {
	enum { MAXLINES_ = 16 };

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
	unsigned long long total = 0;
	unsigned long long ans = 0;
	unsigned int num = 0;

	int off = 0;
	char op = 0;
	while(sscanf(shlines[nlines], "%c %n", &op, &off) != EOF) {
		shlines[nlines] += off;

		ans = (op == '*');
		for(int i = 0; i < nlines; ++i) {
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
