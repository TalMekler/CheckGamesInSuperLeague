#include "Team.h"

int cnt_opt_ = 0, total_opt_ = 0;
const char* teams_name[EXTRA_TEAMS] = { "Haifa", "Maccabi TA", "Beer Sheva", "Natania", "Saknin", "Hapoel TA" };
//Game* games_arr[GAMES] = { 0 };
int team_points[] = {	62, // Haifa
						55, // Maccabi Tel Aviv
						58, // Beer Sheva
						41, // Natania
						43, // Saknin
						41	// Hapoel Tel Aviv
					};
int GAMES = 0;
// Game Branch
int main() {

	
	/* מחזור 2 */
	Game g2_1 = { MHFC, HBS, 0 };
	Game g2_3 = { Sak, Nat, 0 };

	/* מחזור 3 */
	Game g3_1 = { MTA, MHFC, 0 };
	Game g3_2 = { HBS, HTA, 0 };

	/* מחזור 4 */
	Game g4_1 = { MHFC, Sak, 0 };
	Game g4_2 = { HBS, MTA, 0 };
	Game g4_3 = { HTA, Nat, 0 };

	/* מחזור 5 */
	Game g5_1 = { Nat, MHFC, 0 };
	Game g5_2 = { Sak, HBS, 0 };
	Game g5_3 = { MTA, HTA, 0 };

	/* מחזור 6 */
	Game g6_1 = { HTA, MHFC, 0 };
	Game g6_2 = { Nat, HBS, 0 };
	Game g6_3 = { Sak, MTA, 0 };

	/* מחזור 7 */
	Game g7_1 = { HBS, MHFC, 0 };
	Game g7_2 = { MTA, Nat, 0 };
	Game g7_3 = { Sak, HTA, 0 };

	/* מחזור 8 */
	Game g8_1 = { MHFC, MTA, 0 };
	Game g8_2 = { HTA, HBS, 0 };
	Game g8_3 = { Nat, Sak, 0 };

	/* מחזור 9 */
	Game g9_1 = { Sak, MHFC, 0 };
	Game g9_2 = { MTA, HBS, 0 };
	Game g9_3 = { Nat, HTA, 0 };

	/* מחזור 10 */
	Game g10_1 = { MHFC, Nat, 0 };
	Game g10_2 = { HBS, Sak, 0 };
	Game g10_3 = { HTA, MTA, 0 };

	Game* games_arr[] = { &g2_1, &g2_3, &g3_1, &g3_2, &g4_1, &g4_2, &g4_3
						,&g5_1, &g5_2, &g5_3, &g6_1, &g6_2,&g6_3, &g7_1, &g7_2, &g7_3, &g8_1, &g8_2, &g8_3,
						&g9_1, &g9_2, &g9_3, &g10_1, &g10_2, &g10_3 };

	GAMES = sizeof(games_arr) / sizeof(Game*);
	Team* teams_arr[TEAMS];
	makeTeamArr(&teams_arr);
	resetTeamPoints(&teams_arr);
	addGameToTeam(&teams_arr, &games_arr);
	func(&games_arr, GAMES, &teams_arr);
	freeTeamArr(&teams_arr);
	
	printEnd();

	printf("Done!\n");

	return 0;
}