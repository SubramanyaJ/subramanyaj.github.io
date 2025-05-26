/* Earliest Deadline First */

#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define STRCAST (struct Task *)

struct Task {
	int
		PID,
		CT, /* Completion Time */
		RT, /* Remaining Time */
		PER, /* Period */
		NR, /* Next Deadline */
		DL, /* Deadline */
		ADL; /* Absolute Deadline */
};

int
compare(const void *x, const void *y) {
	return (STRCAST x)->ADL - (STRCAST y)->ADL;
}

void
schedule_edf(struct Task *arr, int n, int maxtime) {
	for(int time = 0; time < maxtime; time++) {
		for(int i = 0; i < n; i++) {
			if(time == arr[i].NR) {
				arr[i].NR += arr[i].PER;
				arr[i].RT = arr[i].CT;
				arr[i].ADL = arr[i].DL + time;
				printf("Time %d : Task %d released, deadline %d\n", time, arr[i].PID, arr[i].ADL);
			}	
		}
		qsort(arr, n, sizeof(struct Task), compare);

		int exec = 0;
		for(int i = 0; i < n; i++) {
			if(arr[i].RT > 0 && arr[i].ADL > time) {
				arr[i].RT--;
				exec = 1;

				if(arr[i].RT == 0) {
					printf("Time %d : Task %d comeplete.\n", time + 1, arr[i].PID);	
					if(time + 1 > arr[i].ADL) {
						printf("Deadline missed!\n");
					}
				}	break;
			}
		}
		if(!exec) {
			printf("Time %d : IDLE\n", time);
		}
	}
}

int main() {
	struct Task arr[MAX] = {
		{1, 2, 0, 5, 0, 5, 0},  // Task 1: CT=2, Period=5
		{2, 1, 0, 3, 0, 3, 0},  // Task 2: CT=1, Period=3
		{3, 1, 0, 7, 0, 7, 0}   // Task 3: CT=1, Period=7
	};

	schedule_edf(arr, 3, 30);
	return 0;
}
