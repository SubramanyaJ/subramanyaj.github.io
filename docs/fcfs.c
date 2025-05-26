/* FCFS */

#include <stdio.h>
#include "process.h"
#include <stdlib.h>

int compare(const void *x, const void *y) {
	return ((struct Process *) x)->AT - ((struct Process *) y)->AT;
}


void
schedule_fcfs(struct Process *arr, int n) {
	qsort(arr, n, sizeof(struct Process), compare);

	int time = 0;
	for(int i = 0; i < n; i++) {
idle:
		if(time < arr[i].AT) {
			time++;
			goto idle;
		}
		arr[i].RT = time;
		arr[i].WT = time - arr[i].AT;
		time += arr[i].BT;
		arr[i].CT = time;
		arr[i].TAT = time - arr[i].AT;

	}
	

}

int
main() {
	int n;
	struct Process *arr = get_input(&n, 0);

	schedule_fcfs(arr, n);
	display_processes(arr, n);

	free(arr);
	return 0;
}
