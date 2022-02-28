#pragma once
#include <stdio.h>
#include <stdlib.h>

#define TEAMS 5
#define GAMES 7
#define MAX_TEAM_IN_PLAYOFF 3
// Global vars for team
enum teams { Nat = 0, Had, Sak, Hap, KS };
const char* _teams_name[] = { "Maccabi Natania", "Hapoel Hadera", "Bnei Saknin", "Hapoel Tel Aviv", "Kiryat Shmona" };
// Global Vars
int _cnt_opt = 0;
int _total_opt = 0;

typedef struct {
	int id;
	int points;
} Team;


// Declerations
void func(int* arr, int size, Team* teams);
void calcPoints(int* recursion_arr, Team* teams, int size);
void printTeams(Team* teams, int size, int* recursion_arr, int size2);
int isInPlayoff(Team* sorted, int team_id);
Team cpyTeam(Team* t);
Team* sortTeamsByPoints(Team* teams, int size);

// Declerations Game
void printArr(int* arr, int size);
void printGames(int* recursion_arr);

