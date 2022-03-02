#include "Header.h"
//Main Branch


void printPercent(float num) {
	if (num == (int)num)
		printf("(%d%%)", (int)num);
	else
		printf("(%.2f%%)", num);
}