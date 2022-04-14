#pragma once
//Game Branch
#ifndef HEADER_DEBUG
#define HEADER_DEBUG 1

#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

#define TEAMS 6 // **** Number of the teams you want to check ****
#define EXTRA_TEAMS 6 // **** If there is no EXTRA TEAM -> value = TEAMS value ****
#define MAX_TEAM_IN_PLAYOFF 6
#define MAX_GAMES_TO_RUN 15

// Global Vars
extern int cnt_opt_, total_opt_;
enum teams { MHFC, MTA, HBS, Nat, Sak, HTA };
enum games_res_opt {Lose, Draw, Win = 3};
extern const char* teams_name[EXTRA_TEAMS];
//extern Game* games_arr[GAMES];
extern int team_points[TEAMS];
extern int GAMES;

void printPercent(float num);
void printEnd();

#endif // !TEAM_DEBUG