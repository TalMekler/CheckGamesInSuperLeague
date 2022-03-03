#include "Game.h"

int isGameBelongTeam(Game* game, int team_id) {
	if (game->home_id == team_id || game->guess_id == team_id) return 1;
	return 0;
}

void printGame(Game* game) {
	if (game->game_res == 0) {
		printf("%s-%s: D\n", teams_name[game->home_id], teams_name[game->guess_id]);
	}else 
		if (game->game_res == 1) {
			printf("[%s]-%s\n", teams_name[game->home_id], teams_name[game->guess_id]);
		}
		else {
			printf("%s-[%s]\n", teams_name[game->home_id], teams_name[game->guess_id]);
		}
}

int getPointsToAdd(Game* game, int team_id) {
	if (game->game_res == 0) return Draw;
	if (game->game_res == 1 && game->home_id == team_id) return Win;
	if (game->game_res == 2 && game->guess_id == team_id) return Win;
	return Lose;
}