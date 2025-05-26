#pragma once

#include <stdio.h>
#include <stdlib.h>

struct Process {
	int PID, AT, BT, CT, 
	    TAT, WT, RT, PRI, REM;
};

struct Process *
get_input(int *n, int args);

void
display_processes(struct Process *table, int n);
