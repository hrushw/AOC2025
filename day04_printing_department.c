#include <stdio.h>

enum { LINESZ_ = 1024 };
unsigned char _linearr[3][LINESZ_] = {{0}};
typedef unsigned char* Line;

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

void swotch(Line *l1, Line *l2, Line *l3) {
	Line ltmp = *l1;
	*l1 = *l2;
	*l2 = *l3;
	*l3 = ltmp;
}
void clear(Line l) {
	for(int i = 0; i < LINESZ_; ++i) l[i] = 0;
}

int main(void) {
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

	printf("Accessible rolls: %u\n", out);

	return 0;
}
