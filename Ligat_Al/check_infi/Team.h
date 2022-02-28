#pragma once

// Declerations
void func(int* arr, int size, Team* teams);
void calcPoints(int* recursion_arr, Team* teams, int size);
void printTeams(Team* teams, int size, int* recursion_arr, int size2);
int isInPlayoff(Team* sorted, int team_id);
Team cpyTeam(Team* t);
Team* sortTeamsByPoints(Team* teams, int size);

// Global vars for team
enum teams { Nat = 0, Had, Sak, Hap, KS };
const char* teams_name[] = { "Natania", "Hadera", "Saknin", "Hapoel", "Kiryat Shmona" };

typedef struct {
	int id;
	int points;
} Team;