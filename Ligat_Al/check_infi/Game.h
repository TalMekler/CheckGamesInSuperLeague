#pragma once

#include <stdio.h>
#include <stdlib.h>

#define TEAMS 5
#define GAMES 7
#define MAX_TEAM_IN_PLAYOFF 3
// Global vars for team
enum teams { Nat = 0, Had, Sak, Hap, KS };
const char* teams_name[] = { "Maccabi Natania", "Hapoel Hadera", "Bnei Saknin", "Hapoel Tel Aviv", "Kiryat Shmona" };
// Global Vars
int cnt_opt = 0;
int total_opt = 0;

typedef struct {
	int home_id;
	int guess_id;
	int res;  // this is the main
} Game;

// Declerations
void printArr(int* arr, int size);
void printGames(int* recursion_arr);