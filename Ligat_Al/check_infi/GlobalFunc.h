#pragma once
#include <stdio.h>
#include <stdlib.h>

#define TEAMS 5
#define GAMES 7
#define MAX_TEAM_IN_PLAYOFF 3

// Global Vars
int cnt_opt = 0;
int total_opt = 0;
// Global vars for team
enum teams { Nat = 0, Had, Sak, Hap, KS };
const char* teams_name[] = { "Natania", "Hadera", "Saknin", "Hapoel", "Kiryat Shmona" };

// Declerations
void printArr(int* arr, int size);
void printGames(int* recursion_arr);



