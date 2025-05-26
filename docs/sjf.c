/* SJF */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#include "process.h"

int compare(const void *x, const void *y) {
	return ((struct Process *) x)->BT - ((struct Process *) y)->BT;
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
					&& arr[i].BT < min
					&& time >= arr[i].AT

			  ) {
				idx = i;
				min = arr[i].BT;
			}
		}
		if(idx == -1) {time++; continue;}
		arr[idx].RT = time;
		arr[idx].WT = time - arr[idx].AT;
		time += arr[idx].BT;
		arr[idx].CT = time;
		arr[idx].TAT = time - arr[idx].AT;
		done[idx] = true;
		count++;
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
