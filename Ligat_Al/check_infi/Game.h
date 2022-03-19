#pragma once
#ifndef GAME_DEBUG
#define GAME_DEBUG
#include "Header.h"


typedef struct {
	int home_id;
	int guess_id;
	int game_res; // 0 / 1 / 2
} Game;

int isGameBelongTeam(Game* game, int team_id);
void printGame(Game* game);
void printGames(Game** games_arr);
int getPointsToAdd(Game* game, int team_id);
void addRound(Game** games_arr, int* games_arr_size, Game* round_arr, int round_arr_size, int round_num);
#endif // !GAME_DEBUG
