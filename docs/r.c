/* Round Robin */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#include "process.h"

void
schedule_rr(struct Process *arr, int n, int tq) {

	int time = 0, count = 0;
	bool done[n];
	memset(done, 0x00, n);

	while(count < n) {
		bool progress = false;
		for(int idx = 0; idx < n; idx++) {
			if(arr[idx].AT <= time && !done[idx]) {
				if(arr[idx].REM == arr[idx].BT) {
					arr[idx].RT = time;
				}
				int sub = (tq > arr[idx].REM) ? arr[idx].REM : tq;
				arr[idx].REM -= sub;
				time += sub;
				progress = true;
				if(arr[idx].REM == 0) {
					arr[idx].CT = time;
					arr[idx].TAT = arr[idx].CT - arr[idx].AT;
					arr[idx].WT = arr[idx].TAT - arr[idx].BT;
					done[idx] = true;
					count++;
				}
			}
		}
		if(!progress){time++;}
	}
}

int
main() {
	int n;
	struct Process *arr = get_input(&n, 0);

	schedule_rr(arr, n, 2);
	display_processes(arr, n);

	free(arr);
	return 0;
}
