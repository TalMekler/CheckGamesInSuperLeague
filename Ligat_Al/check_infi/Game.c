#include "Game.h"

int isGameBelongTeam(Game* game, int team_id) {
	if (game->home_id == team_id || game->guess_id == team_id) return 1;
	return 0;
}

void printGame(Game* game) {
	if (game->game_res == 0) {
		printf("%s-%s: D", teams_name[game->home_id], teams_name[game->guess_id]);
	}else 
		if (game->game_res == 1) {
			printf("[%s]-%s", teams_name[game->home_id], teams_name[game->guess_id]);
		}
		else {
			printf("%s-[%s]", teams_name[game->home_id], teams_name[game->guess_id]);
		}
}

void printGames(Game** games_arr) {
	for (int i = 0; i < GAMES; i++) {
		printGame(games_arr[i]);
		if (i + 1 < GAMES) {
			printf(", ");
		}
	}
	printf("\n");
}

int getPointsToAdd(Game* game, int team_id) {
	if (game->game_res == 0) return Draw;
	if (game->game_res == 1 && game->home_id == team_id) return Win;
	if (game->game_res == 2 && game->guess_id == team_id) return Win;
	return Lose;
}

void addRound(Game** games_arr, int* games_arr_size, Game* round_arr, int round_arr_size, int round_num) {
	printf("Start adding round number %d \n", round_num);

	for (int i = 0; i < round_arr_size; i++) {
		*games_arr[*games_arr_size] = round_arr[i];
		++* games_arr_size;

	}
	
	printf("Round number %d added! \n", round_num);
}