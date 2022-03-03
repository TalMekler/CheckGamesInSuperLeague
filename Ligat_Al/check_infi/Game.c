#include "Game.h"

int isGameBelongTeam(Game* game, int team_id) {
	if (game->home_id == team_id || game->guess_id == team_id) return 1;
	return 0;
}