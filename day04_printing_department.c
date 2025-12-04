#include <stdio.h>

enum { LINESZ_ = 1024 };
typedef unsigned char* Line;
typedef unsigned char Grid[LINESZ_][LINESZ_];

int chkroll(char c) {
	return (c == '@' || c == 'M');
}

unsigned int nhbd(Line l, Line lp, Line ln, int i) {
	unsigned int n = 0;

	if(lp[i] == '@') n += 1;
	if(ln[i] == '@') n += 1;

	if(lp[i+1] == '@') n += 1;
	if(ln[i+1] == '@') n += 1;
	if(l [i+1] == '@') n += 1;

	if(!i) return n;

	if(lp[i-1] == '@') n += 1;
	if(ln[i-1] == '@') n += 1;
	if(l [i-1] == '@') n += 1;
	return n;
}

unsigned int nhbd2d(Grid g, int i, int j) {
	unsigned int n = 0;
	if(!i) return n;

	if(chkroll(g[i-1][j  ])) n += 1;
	if(chkroll(g[i+1][j  ])) n += 1;

	if(chkroll(g[i  ][j+1])) n += 1;
	if(chkroll(g[i+1][j+1])) n += 1;
	if(chkroll(g[i-1][j+1])) n += 1;

	if(!j) return n;
	if(chkroll(g[i-1][j-1])) n += 1;
	if(chkroll(g[i  ][j-1])) n += 1;
	if(chkroll(g[i+1][j-1])) n += 1;

	return n;
}

void swotch(Line *l1, Line *l2, Line *l3) {
	Line ltmp = *l1;
	*l1 = *l2;
	*l2 = *l3;
	*l3 = ltmp;
}
void clear(Line l) {
	for(int i = 0; i < LINESZ_; ++i) l[i] = 0;
}

unsigned int part1(void) {
	static unsigned char _linearr[3][LINESZ_] = {{0}};
	Line lprev = _linearr[0];
	Line lcur = _linearr[1];
	Line lnext = _linearr[2];
	int i;
	unsigned int out = 0;

	int scanstatus = 0;
	do {
		scanstatus = scanf("%s\n", lnext);
		for(i = 0; i < LINESZ_; ++i)
			if(lcur[i] == '@' && nhbd(lcur, lprev, lnext, i) < 4) out += 1;

		swotch(&lprev, &lcur, &lnext);
		clear(lnext);
	} while(scanstatus != EOF);

	return out;
}

void clearmarks(Grid g) {
	for(unsigned int i = 1; g[i][0]; ++i)
		for(unsigned int j = 0; g[i][j]; ++j)
			if(g[i][j] == 'M') g[i][j] = '.';
}

unsigned int part2(void) {
	static Grid _linearr = {{0}};
	unsigned int i, j;
	for(i = 1; scanf("%s\n", _linearr[i]) != EOF; ++i);

	unsigned int work, out = 0;
	do {
		work = 0;
		for(i = 1; _linearr[i][0]; ++i)
			for(j = 0; _linearr[i][j]; ++j)
				if(_linearr[i][j] == '@' && nhbd2d(_linearr, i, j) < 4) {
					work += 1;
					_linearr[i][j] = 'M';
				}
		clearmarks(_linearr);
		out += work;
	} while(work);
	return out;
}

int main(void) {
	unsigned int out = part2();
	printf("Accessible rolls: %u\n", out);

	return 0;
}
