#include "Team.h"
#include "Header.h"

int cnt_opt_ = 0, total_opt_ = 0;
const char* teams_name[EXTRA_TEAMS] = { "Haifa", "Maccabi TA", "Beer Sheva", "Natania", "Saknin", "Hapoel TA" };
//Game* games_arr[GAMES] = { 0 };
int team_points[] = { 59, 53, 55, 40, 42, 38 }; // Haifa, Maccabi TA, Beer Sheva, Natania, Saknin, Hapoel TA
int GAMES = 0;
// Game Branch
int main() {


	/* מחזור 1 */
	Game g1_1 = { MHFC, HTA, 0 };
	Game g1_2 = { HBS, Nat, 0 };
	Game g1_3 = { MTA, Sak, 0 };
	Game* games1[] = { &g1_1, &g1_2, &g1_3 };
	
	/* מחזור 2 */
	Game g2_1 = { MHFC, HBS, 0 };
	Game g2_2 = { Nat, MTA, 0 };
	Game g2_3 = { Sak, Nat, 0 };
	Game* games2[] = { &g2_1, &g2_2, &g2_3 };

	/* מחזור 3 */
	Game g3_1 = { MTA, MHFC, 0 };
	Game g3_2 = { HBS, HTA, 0 };
	Game g3_3 = { HTA, Sak, 0 };
	Game* games3[] = { &g3_1, &g3_2, &g3_3 };

	/* מחזור 4 */
	Game g4_1 = { MHFC, Sak, 0 };
	Game g4_2 = { HBS, MTA, 0 };
	Game g4_3 = { HTA, Nat, 0 };
	Game* games4[] = { &g4_1, &g4_2, &g4_3 };

	/* מחזור 5 */
	Game g5_1 = { Nat, MHFC, 0 };
	Game g5_2 = { Sak, HBS, 0 };
	Game g5_3 = { MTA, HTA, 0 };
	Game* games5[] = { &g5_1, &g5_2, &g5_3 };

	/* מחזור 6 */
	Game g6_1 = { HTA, MHFC, 0 };
	Game g6_2 = { Nat, HBS, 0 };
	Game g6_3 = { Sak, MTA, 0 };
	Game* games6[] = { &g6_1, &g6_2, &g6_3 };

	/* מחזור 7 */
	Game g7_1 = { HBS, MHFC, 0 };
	Game g7_2 = { MTA, Nat, 0 };
	Game g7_3 = { Sak, HTA, 0 };
	Game* games7[] = { &g7_1, &g7_2, &g7_3 };

	/* מחזור 8 */
	Game g8_1 = { MHFC, MTA, 0 };
	Game g8_2 = { HTA, HBS, 0 };
	Game g8_3 = { Nat, Sak, 0 };
	Game* games8[] = { &g8_1, &g8_2, &g8_3 };

	/* מחזור 9 */
	Game g9_1 = { Sak, MHFC, 0 };
	Game g9_2 = { MTA, HBS, 0 };
	Game g9_3 = { Nat, HTA, 0 };
	Game* games9[] = { &g9_1, &g9_2, &g9_3 };

	/* מחזור 10 */
	Game g10_1 = { MHFC, Nat, 0 };
	Game g10_2 = { HBS, Sak, 0 };
	Game g10_3 = { HTA, MTA, 0 };
	Game* games10[] = { &g10_1, &g10_2, &g10_3 };

	/*Game* games_arr[] = { &g1_1, &g1_2, &g1_3, &g2_1, &g2_2, &g2_3, &g3_1, &g3_2, &g3_3, &g4_1, &g4_2, &g4_3
						,&g5_1, &g5_2, &g5_3, &g6_1, &g6_2,&g6_3, &g7_1, &g7_2, &g7_3, &g8_1, &g8_2, &g8_3,
						&g9_1, &g9_2, &g9_3, &g10_1, &g10_2, &g10_3 };*/
	Game* games_arr;
	
	//printf("Start: %d", sizeof(games_arr) / sizeof(Game*));

	addGamesTo_gamesArr(&games_arr, &games1, GAMES_PER_REOUND);
	/*addGamesTo_gamesArr(&games_arr, &games2, GAMES_PER_REOUND);
	addGamesTo_gamesArr(&games_arr, &games3, GAMES_PER_REOUND);
	addGamesTo_gamesArr(&games_arr, &games4, GAMES_PER_REOUND);
	addGamesTo_gamesArr(&games_arr, &games5, GAMES_PER_REOUND);
	addGamesTo_gamesArr(&games_arr, &games6, GAMES_PER_REOUND);
	addGamesTo_gamesArr(&games_arr, &games7, GAMES_PER_REOUND);
	addGamesTo_gamesArr(&games_arr, &games8, GAMES_PER_REOUND);
	addGamesTo_gamesArr(&games_arr, &games9, GAMES_PER_REOUND);
	addGamesTo_gamesArr(&games_arr, &games10, GAMES_PER_REOUND);*/

	printf("End: %d", sizeof(games_arr) / sizeof(Game*));
	exit(1);


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