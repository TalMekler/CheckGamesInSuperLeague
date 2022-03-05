#include "Team.h"

int cnt_opt_ = 0, total_opt_ = 0;
const char* teams_name[EXTRA_TEAMS] = { "Natania", "Hadera", "Saknin", "Hapoel TA", "Kiryat Shmona", "Maccabi TA", "Ashdod", "Hapoel Jer", "Petach Tikva"};
//Game* games_arr[GAMES] = { 0 };
int team_points[] = { 39,36,39,37}; // Natania, Hadera, Saknin, Hapoel TA
int GAMES = 0;
// Game Branch
int main() {

	/*Game g1 = { Nat, KS, 0 };*/
	Game g2 = { Hap, Nat, 0 };
	/*Game g3 = { Sak, Had, 0 };*/
	Game g4 = { Had, MTA, 0 };
	Game g5 = { PTH, Sak, 0 };
	/*Game g6 = { HJER, Hap, 0 };*/
	Game g7 = { KS, ASH, 0 };
	Game* games_arr[] = { /*&g1,*/&g2,/*&g3,*/&g4,&g5,/*&g6,*/&g7 };
	GAMES = sizeof(games_arr) / sizeof(Game*);
	Team* teams_arr[TEAMS];
	makeTeamArr(&teams_arr);
	resetTeamPoints(&teams_arr);
	addGameToTeam(&teams_arr, &games_arr);
	func(&games_arr, GAMES, &teams_arr);
	freeTeamArr(&teams_arr);
	printf(">>> Games remined: %d <<<\n", GAMES);
	printf(">>> There are %d/%d combinations ", cnt_opt_, total_opt_); printPercent(((float)cnt_opt_ / total_opt_) * 100); printf(" <<<\n");

	printf("done!\n");

	return 0;
}