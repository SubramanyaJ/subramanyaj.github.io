/* SJF Preemptive */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#include "process.h"

int compare(const void *x, const void *y) {
	return ((struct Process *) x)->PRI - ((struct Process *) y)->PRI;
}


void
schedule_sjf(struct Process *arr, int n) {

	int time = 0, count = 0;
	bool done[n];
	memset(done, 0x00, n);

	while(count < n) {

		int idx = -1, min = INT_MAX;
		for(int i = 0; i < n; i++) {
			if(
					!done[i]
					&& arr[i].REM < min
					&& time >= arr[i].AT

			  ) {
				idx = i;
				min = arr[i].REM;
			}
		}

		if(idx == -1) {time++; continue;}

		if(arr[idx].REM == arr[idx].BT) {
			arr[idx].RT = time;
		}
		arr[idx].REM--;
		if(arr[idx].REM == 0) {
			arr[idx].CT = time + 1;
			arr[idx].TAT = arr[idx].CT - arr[idx].AT;
			arr[idx].WT = arr[idx].TAT - arr[idx].BT;
			done[idx] = true;
			count++;
		}
		time++;

	}
}

int
main() {
	int n;
	struct Process *arr = get_input(&n, 0);

	schedule_sjf(arr, n);
	display_processes(arr, n);

	free(arr);
	return 0;
}
