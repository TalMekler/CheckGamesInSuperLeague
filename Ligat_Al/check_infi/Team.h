#pragma once

#include <stdio.h>
#include <stdlib.h>

#define GAMES 7
#define TEAMS 5
#define MAX_TEAM_IN_PLAYOFF 3

enum teams { Nat = 0, Had, Sak, Hap, KS };
const char* teams_name[] = { "Natania", "Hadera", "Saknin", "Hapoel", "Kiryat Shmona" };

// Global Vars
int cnt_opt = 0, total_opt = 0;

