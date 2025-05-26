#include "process.h"

#include <stdio.h>

struct Process *
get_input(int *n, int args) {
	printf("Enter the number of processes : ");
	scanf("%d", n);

	struct Process *table = calloc(*n, sizeof(struct Process));

	for(int i = 0; i < *n; i++) {
		printf("Arrival Time [%d] : ", i + 1);
		scanf("%d", &table[i].AT);
		printf("Burst Time [%d] : ", i + 1);
		scanf("%d", &table[i].BT);
		table[i].REM = table[i].BT;

		if(args == 1) {
			printf("Priority : [%d] : ", i + 1);		
			scanf("%d", &table[i].PRI);
		}

		table[i].PID = i + 1;	
	}

	return table;
}

void
display_processes(struct Process *table, int n) {
	printf("PID\tAT\tBT\tCT\tTAT\tWT\tRT\tPriority\n");
	for(int i = 0; i < n; i++) {
		printf(
			"%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
			table[i].PID,
			table[i].AT,
			table[i].BT,
			table[i].CT,
			table[i].TAT,
			table[i].WT,
			table[i].RT,
			table[i].PRI
		);
	}
}
