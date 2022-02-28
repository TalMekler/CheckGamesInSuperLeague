#include "Game.h"

void printArr(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void printGames(int* recursion_arr) {
	if (recursion_arr[0] == 1)
		printf("[%s]-%s, ", teams_name[Nat], teams_name[KS]);
	else if (recursion_arr[0] == 0)
		printf("%s-%s: D, ", teams_name[Nat], teams_name[KS]);
	else
		printf("%s-[%s], ", teams_name[Nat], teams_name[KS]);

	if (recursion_arr[1] == 1)
		printf("[%s]-%s, ", teams_name[Hap], teams_name[Nat]);
	else
		if (recursion_arr[1] == 2)
			printf("%s-[%s], ", teams_name[Hap], teams_name[Nat]);
		else {
			printf("%s-%s: D, ", teams_name[Nat], teams_name[Hap]);
		}

	if (recursion_arr[2] == 1)
		printf("[%s]-%s, ", teams_name[Sak], teams_name[Had]);
	else
		if (recursion_arr[2] == 2)
			printf("%s-[%s], ", teams_name[Sak], teams_name[Had]);
		else {
			printf("%s-%s: D, ", teams_name[Sak], teams_name[Had]);
		}

	if (recursion_arr[3] == 1)
		printf("[%s]-Maccabi, ", teams_name[Had]);
	else if (recursion_arr[3] == 0)
		printf("%s-Maccabi: D, ", teams_name[Had]);
	else
		printf("%s-[Maccabi], ", teams_name[Had]);


	if (recursion_arr[4] == 2)
		printf("PT-[%s], ", teams_name[Sak]);
	else if (recursion_arr[4] == 0)
		printf("PT-%s: D, ", teams_name[Sak]);
	else
		printf("[PT]-%s, ", teams_name[Sak]);

	if (recursion_arr[5] == 2)
		printf("Jerusalem-[%s], ", teams_name[Hap]);
	else if (recursion_arr[5] == 0)
		printf("Jerusalem-%s: D, ", teams_name[Hap]);
	else
		printf("[Jerusalem]-%s, ", teams_name[Hap]);

	if (recursion_arr[6] == 1)
		printf("[%s]-Ashdod, ", teams_name[KS]);
	else if (recursion_arr[7] == 0)
		printf("%s-Ashdod: D, ", teams_name[KS]);
	else
		printf("%s-[Ashdod], ", teams_name[KS]);

	printf("\n");
}