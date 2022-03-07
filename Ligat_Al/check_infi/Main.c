#include "Team.h"

int cnt_opt_ = 0, total_opt_ = 0;
const char* teams_name[EXTRA_TEAMS] = { "Haifa", "Maccabi TA", "Beer Sheva", "Natania", "Saknin", "Hapoel TA" };
//Game* games_arr[GAMES] = { 0 };
int team_points[] = { 59, 55, 50, 39, 42, 40}; // Natania, Hadera, Saknin, Hapoel TA
int GAMES = 0;
// Game Branch
int main() {

	// Maccabi Haifa
	Game g1 = { MHFC, MTA, 0 };
	Game g2 = { MHFC, HBS, 0 };
	Game g3 = { MHFC, Nat, 0 };
	Game g4 = { MHFC, Sak, 0 };
	Game g5 = { MHFC, HTA, 0 };
	// Maccabi Tel Aviv
	Game g6 = { MTA, MHFC, 0 };
	Game g7 = { MTA, HBS, 0 };
	Game g8 = { MTA, Nat, 0 };
	Game g9 = { MTA, Sak, 0 };
	Game g10 = { MTA, HTA, 0 };
	// Hapoel Beer Sheva
	Game g11 = { HBS, MHFC, 0 };
	Game g12 = { HBS, MTA, 0 };
	Game g13 = { HBS, Nat, 0 };
	Game g14 = { HBS, Sak, 0 };
	Game g15 = { HBS, HTA, 0 };
	// Maccabi Natania
	Game g16 = { Nat, MHFC, 0 };
	Game g17 = { Nat, MTA, 0 };
	Game g18 = { Nat, HBS, 0 };
	Game g19 = { Nat, Sak, 0 };
	Game g20 = { Nat, HTA, 0 };
	// Bnei Saknin
	Game g21 = { Sak, MHFC, 0 };
	Game g22 = { Sak, MTA, 0 };
	Game g23 = { Sak, HBS, 0 };
	Game g24 = { Sak, Nat, 0 };
	Game g25 = { Sak, HTA, 0 };
	// Hapoel Tel Aviv
	Game g26 = { HTA, MHFC, 0 };
	Game g27 = { HTA, MTA, 0 };
	Game g28 = { HTA, HBS, 0 };
	Game g29 = { HTA, Nat, 0 };
	Game g30 = { HTA, Sak, 0 };
	Game* games_arr[] = { &g1, &g2, &g3, &g4, &g5, &g6, &g7, &g8, &g9, &g10, &g11, &g12, &g13, &g14, &g15, &g16, &g17, &g18, &g19, &g20, &g21, &g22, &g23, &g24, &g25, &g26, &g27, &g28, &g29, &g30 };
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