#include "Team.h"
#include "Header.h"
//Game Branch

void printArr(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void func(Game** games_arr, int size, Team** teams_arr) {
	if (size == 0) {
		calcPoints(teams_arr, games_arr);
		return;
	}

	for (int i = 0; i <= 2; i++) { // recursion options
		games_arr[size - 1]->game_res = i;
		func(games_arr, size - 1, teams_arr);
	}
}

void calcPoints(Team** teams_arr, Game** games_arr) {
	resetTeamPoints(teams_arr);
	for (int i = 0; i < TEAMS; i++) {
		for (int j = 0; j < teams_arr[i]->num_of_games; j++) {
			teams_arr[i]->points += getPointsToAdd(teams_arr[i]->games[j], teams_arr[i]->id);
		}
	}
	printTeams(teams_arr, games_arr);
}

void printTeams(Team** teams_arr, Game** games_arr) {
	Team** res;
	int stop_at = 5000;
	res = sortTeamsByPoints(teams_arr);

	total_opt_++;

	if (res[4]->id == HTA) {
		cnt_opt_++;
		printData(res, games_arr);
		
		if (cnt_opt_ >= stop_at && stop_at != 0) {
			printEnd();
			printf("\nThe program found %d options.\nDone!", stop_at);
			exit(1);
		}
	}
	for (int i = 0; i < TEAMS; i++) {
		free(res[i]->games);
		free(res[i]);
	}
	free(res);
	res = NULL;

}

Team* cpyTeam(Team* t) {
	Team* cpy = (Team*)calloc(1, sizeof(Team));
	cpy->id = t->id;
	cpy->points = t->points;
	return cpy;
}

Team** sortTeamsByPoints(Team** teams_arr) {
	Team** res = (Team**)calloc(TEAMS, sizeof(Team*));
	Team* tmp;

	for (int i = 0; i < TEAMS; i++) {
		res[i] = cpyTeam(teams_arr[i]);
	}
	for (int i = 0; i < TEAMS; i++) {
		for (int j = 0; j < TEAMS - 1 - i; j++) {
			if (res[j]->points < res[j + 1]->points) {
				tmp = res[j];
				res[j] = res[j + 1];
				res[j + 1] = tmp;
			}
		}
	}
	return res;
}

int isInPlayoff(Team** sorted, int team_id) {
	for (int i = 0; i < MAX_TEAM_IN_PLAYOFF; i++) {
		if (sorted[i]->id == team_id) return 1;
	}
	return 0;
}

void printData(Team** res, Game** games_arr) {
	printGames(games_arr);
	printf("========== (%d) ==========\n", cnt_opt_);
	for (int i = 0; i < TEAMS; i++) {
		if (i == MAX_TEAM_IN_PLAYOFF)
			printf("-------------------- \n");
		printf("%d) %s: %d\n", i + 1, teams_name[res[i]->id], res[i]->points);
	}
	printf("======================\n\n");
}

int isTeamExist(int team_id) {
	if (team_id >= 0 && team_id < TEAMS) return 1;
	return 0;
}

void resetTeamPoints(Team** team_arr) {
	for (int i = 0; i < TEAMS; i++) {
		team_arr[i]->points = team_points[i];
	}
}

Team* createTeam(int id) {
	Team* t = (Team*)calloc(1, sizeof(Team));
	t->id = id;
	return t;
}

void makeTeamArr(Team** team_arr) {
	for (int i = 0; i < TEAMS; i++) {
		team_arr[i] = createTeam(i);
	}
}

void freeTeam(Team* team) {
	free(team->games);
	free(team);
	team = NULL;
}

void freeTeamArr(Team** team_arr) {
	for (int i = 0; i < TEAMS; i++) {
		freeTeam(team_arr[i]);
	}
}

void addGameToTeam(Team** team_arr, Game** games) {
	for (int i = 0; i < TEAMS; i++) {
		for (int j = 0; j < GAMES; j++) {
			if (isGameBelongTeam(games[j], team_arr[i]->id)) {
				team_arr[i]->games = (Game**)realloc(team_arr[i]->games, sizeof(Game*) * (1 + team_arr[i]->num_of_games));
				team_arr[i]->games[team_arr[i]->num_of_games] = games[j];
				++team_arr[i]->num_of_games;
			}
		}
	}
}