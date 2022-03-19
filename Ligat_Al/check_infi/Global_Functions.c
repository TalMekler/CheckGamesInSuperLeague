#include "Header.h"
//Game Branch


void printPercent(float num) {
	if (num == (int)num)
		printf("(%d%%)", (int)num);
	else
		printf("(%.2f%%)", num);
}

void printEnd() {
	printf(">>> Games remined: %d <<<\n", GAMES);
	printf(">>> There are %d/%d combinations ", cnt_opt_, total_opt_); printPercent(((float)cnt_opt_ / total_opt_) * 100); printf(" <<<\n");
}