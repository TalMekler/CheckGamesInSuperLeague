#pragma once
//Main branch

#ifndef TEAM_DEBUG
#define TEAM_DEBUG
#include "Header.h"

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
#endif