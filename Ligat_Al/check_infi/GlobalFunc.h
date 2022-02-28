#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Team.h"

#define TEAMS 5
#define GAMES 7
#define MAX_TEAM_IN_PLAYOFF 3

// Global Vars
int cnt_opt = 0, total_opt = 0;

// Declerations
void printArr(int* arr, int size);
void printGames(int* recursion_arr);