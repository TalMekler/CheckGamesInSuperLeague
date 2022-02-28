#pragma once

#ifndef HEADER_DEBUG
#define HEADER_DEBUG 1

#include <stdio.h>
#include <stdlib.h>

#define GAMES 7
#define TEAMS 5
#define MAX_TEAM_IN_PLAYOFF 3

// Global Vars
int cnt_opt_ = 0, total_opt_ = 0;
enum teams { Nat = 0, Had, Sak, Hap, KS };
const char* teams_name[] = { "Natania", "Hadera", "Saknin", "Hapoel", "Kiryat Shmona" };

#endif // !TEAM_DEBUG