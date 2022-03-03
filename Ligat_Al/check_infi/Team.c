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
		calcPoints(teams_arr);
		return;
	}

	for (int i = 0; i <= 2; i++) { // recursion options
		games_arr[size - 1]->game_res = i;
		func(games_arr, size - 1, teams_arr);
	}
}

void calcPoints(Team** teams_arr) {
	resetTeamPoints(teams_arr);
	for (int i = 0; i < TEAMS; i++) {
		for (int j = 0; j < teams_arr[i]->num_of_games; j++) {
			teams_arr[i]->points += getPointsToAdd(teams_arr[i]->games[j], teams_arr[i]->id);
		}
	}
}

void printTeams(Team* teams, int size, int* recursion_arr, int size2) {
	Team* res;
	res = sortTeamsByPoints(teams, size);
	total_opt_++;
	if (isInPlayoff(res, Hap)) {
		cnt_opt_++;
		printData(res, recursion_arr);
	}
	free(res);
	res = NULL;

}

Team cpyTeam(Team* t) {
	Team cpy;
	cpy.id = t->id;
	cpy.points = t->points;
	return cpy;
}

Team* sortTeamsByPoints(Team* teams, int size) {
	Team* res = (Team*)calloc(TEAMS, sizeof(Team));
	Team tmp;

	for (int i = 0; i < TEAMS; i++) {
		res[i] = cpyTeam(&teams[i]);
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (res[j].points < res[j + 1].points) {
				tmp = res[j];
				res[j] = res[j + 1];
				res[j + 1] = tmp;
			}
		}
	}
	return res;
}

void printGames(int* recursion_arr) {
	if (recursion_arr[0] == 1)
		printf("[%s]-%s, ", teams_name[Nat], teams_name[KS]);
	else if (recursion_arr[0] == 0)
		printf("%s-%s: D, ", teams_name[Nat], teams_name[KS]);
	else
		printf("%s-[%s], ", teams_name[Nat], teams_name[KS]);

	if (recursion_arr[1] == 1)
		printf("[%s]-%s, ", teams_name[Hap], teams_name[Nat]);
	else
		if (recursion_arr[1] == 2)
			printf("%s-[%s], ", teams_name[Hap], teams_name[Nat]);
		else {
			printf("%s-%s: D, ", teams_name[Nat], teams_name[Hap]);
		}

	if (recursion_arr[2] == 1)
		printf("[%s]-%s, ", teams_name[Sak], teams_name[Had]);
	else
		if (recursion_arr[2] == 2)
			printf("%s-[%s], ", teams_name[Sak], teams_name[Had]);
		else {
			printf("%s-%s: D, ", teams_name[Sak], teams_name[Had]);
		}

	if (recursion_arr[3] == 1)
		printf("[%s]-Maccabi, ", teams_name[Had]);
	else if (recursion_arr[3] == 0)
		printf("%s-Maccabi: D, ", teams_name[Had]);
	else
		printf("%s-[Maccabi], ", teams_name[Had]);


	if (recursion_arr[4] == 2)
		printf("PT-[%s], ", teams_name[Sak]);
	else if (recursion_arr[4] == 0)
		printf("PT-%s: D, ", teams_name[Sak]);
	else
		printf("[PT]-%s, ", teams_name[Sak]);

	if (recursion_arr[5] == 2)
		printf("Jerusalem-[%s], ", teams_name[Hap]);
	else if (recursion_arr[5] == 0)
		printf("Jerusalem-%s: D, ", teams_name[Hap]);
	else
		printf("[Jerusalem]-%s, ", teams_name[Hap]);

	if (recursion_arr[6] == 1)
		printf("[%s]-Ashdod, ", teams_name[KS]);
	else if (recursion_arr[7] == 0)
		printf("%s-Ashdod: D, ", teams_name[KS]);
	else
		printf("%s-[Ashdod], ", teams_name[KS]);

	printf("\n");
}

int isInPlayoff(Team* sorted, int team_id) {
	for (int i = 0; i < MAX_TEAM_IN_PLAYOFF; i++) {
		if (sorted[i].id == team_id) return 1;
	}
	return 0;
}

void printData(Team* res, int* recursion_arr) {
	printGames(recursion_arr);
	printf("========== (%d) ==========\n", cnt_opt_);
	for (int i = 0; i < TEAMS; i++) {
		if (i == 3)
			printf("-------------------- \n");
		printf("%d) %s: %d\n", i + 4, teams_name[res[i].id], res[i].points);
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
	for (int i = 0; i < team->num_of_games; i++) {
		free(team->games[i]);
	}
	free(team->games);
	free(team);
	team = NULL;
}
void freeTeamArr(Team** team_arr) {
	for (int i = 0; i < TEAMS; i++) {
		freeTeam(team_arr[i]);
	}
	free(team_arr);
	team_arr = NULL;
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