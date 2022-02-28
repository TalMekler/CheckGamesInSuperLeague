#include "Team.h"

void func(int* arr, int size, Team* teams) {
	if (size == 0) {
		calcPoints(arr, teams, GAMES);
		return;
	}

	arr[size - 1] = 0;
	func(arr, size - 1, teams);
	arr[size - 1] = 1;
	func(arr, size - 1, teams);
	arr[size - 1] = 2;
	func(arr, size - 1, teams);
}

void calcPoints(int* recursion_arr, Team* teams, int size) {
	int team_points[] = { 36,36,36,34,30 }; // Natania, Hadera, Saknin, Hapoel TA, Kiryat Shmona

	if (recursion_arr[0] == 1)
		team_points[Nat] = team_points[Nat] + 3; // natania win
	else if (recursion_arr[0] == 2)
		team_points[KS] = team_points[KS] + 3;
	else {
		team_points[KS] = team_points[KS] + 1;
		team_points[Nat] = team_points[Nat] + 1;
	}

	if (recursion_arr[1] == 1)
		team_points[Hap] = team_points[Hap] + 3; // hapoel win
	else
		if (recursion_arr[1] == 2)
			team_points[Nat] = team_points[Nat] + 3; // natania win
		else if (recursion_arr[1] == 0) {
			team_points[Nat] = team_points[Nat] + 1;
			team_points[Hap] = team_points[Hap] + 1;
		}

	if (recursion_arr[2] == 1)
		team_points[Sak] = team_points[Sak] + 3; // saknin win
	else
		if (recursion_arr[2] == 2)
			team_points[Had] = team_points[Had] + 3; // hadera
		else if (recursion_arr[2] == 0) {
			team_points[Sak] = team_points[Sak] + 1;
			team_points[Had] = team_points[Had] + 1;
		}

	if (recursion_arr[3] == 1)
		team_points[Had] += 3; // hadera
	else if (recursion_arr[3] == 0)
		team_points[Had] = team_points[Had] + 1;


	if (recursion_arr[4] == 2)
		team_points[Sak] = team_points[Sak] + 3;
	else if (recursion_arr[4] == 0)
		team_points[Sak] = team_points[Sak] + 1;

	if (recursion_arr[5] == 2)
		team_points[Hap] = team_points[Hap] + 3;
	else if (recursion_arr[5] == 0)
		team_points[Hap] = team_points[Hap] + 1;

	if (recursion_arr[6] == 1)
		team_points[KS] = team_points[KS] + 3;
	else if (recursion_arr[7] == 0)
		team_points[KS] = team_points[KS] + 1;



	for (int i = 0; i < TEAMS; i++) {
		teams[i].points = team_points[i];
	}
	printTeams(teams, TEAMS, recursion_arr, GAMES);
	for (int i = 0; i < TEAMS; i++) {
		teams[i].points = 0;
	}
}

void printTeams(Team* teams, int size, int* recursion_arr, int size2) {
	Team* res;
	res = sortTeamsByPoints(teams, size);
	total_opt++;
	if (isInPlayoff(res, Hap)) {
		cnt_opt++;
		//printArr(recursion_arr, size2);
		printGames(recursion_arr);
		printf("========== (%d) ==========\n", cnt_opt);
		for (int i = 0; i < size; i++) {
			if (i == 3)
				printf("-------------------- \n");
			printf("%d) %s: %d\n", i + 4, teams_name[res[i].id], res[i].points);
		}
		printf("======================\n\n");
	}
	free(res);
	res = NULL;
}

int isInPlayoff(Team* sorted, int team_id) {
	for (int i = 0; i < MAX_TEAM_IN_PLAYOFF; i++) {
		if (sorted[i].id == team_id) return 1;
	}
	return 0;
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