#include "Team.h"

// Branch Main - Check
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
	printf(">>> There are %d/%d combinations ", cnt_opt_, total_opt_); printPercent(((float)cnt_opt_ / total_opt_) * 100); printf(" <<<\n");
	return 0;

}