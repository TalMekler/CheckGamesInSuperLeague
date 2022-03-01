#include "Team.h"

// Branch Main
int main() {

	Team t0 = { 0, 0 }; // natania 0
	Team t1 = { 1, 0 }; // hadera 1
	Team t2 = { 2, 0 }; // saknin 2
	Team t3 = { 3, 0 }; // hapoel 3
	Team t4 = { 4, 0 }; // kiryat shmona
	Team t_arr[] = { t0,t1,t2,t3,t4 };
	int arr[GAMES] = { 0 };
	func(arr, GAMES, t_arr);
	printf(">>> Games remined: %d <<<\n", GAMES);
	printf(">>> There are %d/%d combinations <<<\n", cnt_opt_, total_opt_);
	return 0;

}