#pragma once

#ifndef HEADER_DEBUG
#define HEADER_DEBUG 1

#include <stdio.h>
#include <stdlib.h>

#define GAMES 7
#define TEAMS 5
#define MAX_TEAM_IN_PLAYOFF 3

// Global Vars
extern int cnt_opt_, total_opt_;
enum teams { Nat = 0, Had, Sak, Hap, KS };
extern const char* teams_name[TEAMS];

#endif // !TEAM_DEBUG