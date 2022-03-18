#include "Header.h"
//Game Branch


void printPercent(float num) {
	if (num == (int)num)
		printf("(%d%%)", (int)num);
	else
		printf("(%.2f%%)", num);
}

void addGamesTo_gamesArr(Game** big_arr, Game** small_arr, int games_qtt) {
	int big_arr_size = sizeof(big_arr) / sizeof(Game*);
	Game* big_arr = (Game*)realloc(big_arr, big_arr_size + games_qtt);
	if (!big_arr) {
		printf("Allocation Failed! \n");
		exit(1);
	}
	for (int i = 0; i < games_qtt; i++) {
		big_arr[big_arr_size + i] = small_arr[i];
	}
}