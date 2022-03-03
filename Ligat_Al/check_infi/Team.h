#pragma once
//Game branch.

#ifndef TEAM_DEBUG
#define TEAM_DEBUG
#include "Game.h"
//#include "Header.h"

typedef struct {
	int id;
	int points;
	Game** games; // DMA
	int num_of_games;
} Team;

void printArr(int* arr, int size);
int isInPlayoff(Team* sorted, int team_id);
int isTeamExist(int team_id);

// uptaded
void func(Game** games_arr, int size, Team** teams_arr);
void calcPoints(Team** teams_arr);
void resetTeamPoints(Team** team_arr);
Team* createTeam(int id);
void makeTeamArr(Team** team_arr);
void freeTeam(Team* team);
void freeTeamArr(Team** team_arr);
void addGameToTeam(Team** team_arr, Game** games);
Team* cpyTeam(Team* t);
Team** sortTeamsByPoints(Team** teams_arr);
void printGames(Game** games_arr);
void printData(Team** res, Game** games_arr);
void printTeams(Team** teams_arr, Game** games_arr);
#endif