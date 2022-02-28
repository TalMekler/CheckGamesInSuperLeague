#pragma once
#ifndef TEAM_DEBUG
#define TEAM_DEBUG 1

#include <stdio.h>
#include <stdlib.h>

#define GAMES 7
#define TEAMS 5
#define MAX_TEAM_IN_PLAYOFF 3

#ifndef TEAM_DEBUG2
#define TEAM_DEBUG2 1
// Global Vars
int cnt_opt = 0, total_opt = 0;
enum teams { Nat = 0, Had, Sak, Hap, KS };
const char* teams_name[] = { "Natania", "Hadera", "Saknin", "Hapoel", "Kiryat Shmona" };
#endif // !TEAM_DEBUG2



#endif // !TEAM_DEBUG

typedef struct {
	int id;
	int points;
} Team;

void printArr(int* arr, int size);
void func(int* arr, int size, Team* teams);
void calcPoints(int* recursion_arr, Team* teams, int size);
void printTeams(Team* teams, int size, int* recursion_arr, int size2);
Team* sortTeamsByPoints(Team* teams, int size);
void printGames(int* recursion_arr);
Team cpyTeam(Team* t);
int isInPlayoff(Team* sorted, int team_id);

