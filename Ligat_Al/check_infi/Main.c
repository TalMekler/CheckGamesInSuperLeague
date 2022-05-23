#include "Team.h"

int cnt_opt_ = 0, total_opt_ = 0;
const char* teams_name[EXTRA_TEAMS] = { "Haifa", "Maccabi TA", "Beer Sheva", "Natania", "Saknin", "Hapoel TA" };
//Game* games_arr[GAMES] = { 0 };
int team_points[] = {	72, // Haifa
						66, // Maccabi Tel Aviv
						67, // Beer Sheva
						52, // Natania
						50, // Saknin
						49	// Hapoel Tel Aviv
					};
int GAMES = 0;
// Game Branch
int main() {
	/* מחזור 10 */
	Game g10_1 = { MHFC, Nat, 0 };
	Game g10_2 = { HBS, Sak, 0 };
	Game g10_3 = { HTA, MTA, 0 };

	Game* games_arr[] = {&g10_1, &g10_2, &g10_3 };

	GAMES = sizeof(games_arr) / sizeof(Game*);
	int userEnter;
	Team* teams_arr[TEAMS];
	
	if (GAMES < MAX_GAMES_TO_RUN) {
		makeTeamArr(&teams_arr);
		resetTeamPoints(&teams_arr);
		addGameToTeam(&teams_arr, &games_arr);

		func(&games_arr, GAMES, &teams_arr);
		freeTeamArr(&teams_arr);

		printEnd();
	}
	else 
		printf("There are %d games...\nExit program\n", GAMES);
	printf("Done!\n");

	return 0;
}