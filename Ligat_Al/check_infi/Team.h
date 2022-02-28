#pragma once
#include "GlobalFunc.h"

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

