#include "Team.h"

int cnt_opt_ = 0, total_opt_ = 0;
const char* teams_name[TEAMS] = { "Natania", "Hadera", "Saknin", "Hapoel", "Kiryat Shmona" };
//Game* games_arr[GAMES] = { 0 };
int team_points[] = { 36,36,36,34,30 }; // Natania, Hadera, Saknin, Hapoel TA, Kiryat Shmona

// Game Branch
int main() {

	Game g1 = { Nat, KS, 0 };
	Game g2 = { Hap, Nat, 0 };
	Game g3 = { Sak, Had, 0 };
	Game g4 = { Had, -1, 0 };
	Game g5 = { -1, Sak, 0 };
	Game g6 = { -1, Hap, 0 };
	Game g7 = { KS, -1, 0 };
	Game* games_arr[] = { &g1,&g2,&g3,&g4,&g5,&g6,&g7 };
	Team* teams_arr[TEAMS];
	makeTeamArr(&teams_arr);
	resetTeamPoints(&teams_arr);
	addGameToTeam(&teams_arr, &games_arr);
	printf("done!\n");
	
	
	//Team t0 = { 0, 0 }; // natania 0
	//Team t1 = { 1, 0 }; // hadera 1
	//Team t2 = { 2, 0 }; // saknin 2
	//Team t3 = { 3, 0 }; // hapoel 3
	//Team t4 = { 4, 0 }; // kiryat shmona
	//Team t_arr[] = { t0,t1,t2,t3,t4 };
	//int arr[GAMES] = { 0 };
	//func(arr, GAMES, t_arr);
	//printf(">>> Games remined: %d <<<\n", GAMES);
	//printf(">>> There are %d/%d combinations ", cnt_opt_, total_opt_); printPercent(((float)cnt_opt_ / total_opt_) * 100); printf(" <<<\n");
	return 0;

}