#pragma once
//Game Branch
#ifndef HEADER_DEBUG
#define HEADER_DEBUG 1

#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

//#define GAMES 7
#define TEAMS 5
#define EXTRA_TEAMS 9 // **** If there is no EXTRA TEAM -> value = TEAMS value ****
#define MAX_TEAM_IN_PLAYOFF 3

// Global Vars
extern int cnt_opt_, total_opt_;
enum teams { Nat = 0, Had, Sak, Hap, KS, MTA, ASH, HJER, PTH};
enum games_res_opt {Lose, Draw, Win = 3};
extern const char* teams_name[EXTRA_TEAMS];
//extern Game* games_arr[GAMES];
extern int team_points[TEAMS];
extern int GAMES;

void printPercent(float num);

#endif // !TEAM_DEBUG