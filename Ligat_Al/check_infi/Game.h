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
#endif // !GAME_DEBUG
