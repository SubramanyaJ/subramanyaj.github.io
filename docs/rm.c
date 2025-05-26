/* Rate Monotonic */

#include <stdio.h>
#include <stdlib.h>

#define MAX 5
#define STRCAST (struct Task *)

struct Task {
	int
		PID,
		CT, /* Completion Time */
		RT, /* Remaining Time */
		PER, /* Period */
		NR, /* Next Release */
		DL; /* Deadline */
};

int
compare(const void *x, const void *y) {
	return (STRCAST x)->PER - (STRCAST y)->PER;
}

void
schedule_rms(struct Task *arr, int n, int maxtime) {
	for(int time = 0; time < maxtime; time++) {
		for(int i = 0; i < n; i++) {
			if(arr[i].NR == time) {
				if(arr[i].RT > 0) {
					printf("Deadline missed by %d\n", arr[i].PID);
				}
				arr[i].RT = arr[i].CT;
				arr[i].NR += arr[i].PER;
				printf("Time %d : Task %d released, next at %d\n", time, arr[i].PID, arr[i].NR);
			}	
		}

		qsort(arr, n, sizeof(struct Task), compare);

		int exec = 0;
		for(int i = 0; i < n; i++) {
			if(arr[i].RT > 0) {
				printf("Time %d : Executing task %d.\n", time, arr[i].PID);
				arr[i].RT--;
				exec = 1;
				if(arr[i].RT == 0) {
					printf("Time %d : Task %d comeplete.\n", time + 1, arr[i].PID);	
				} break;
			}		
		}
		if(!exec) {
			printf("Time %d : IDLE\n", time);
		}
	}
}

int main() {
	struct Task arr[MAX] = {
		{1, 2, 0, 5, 0, 5},  // Task 1: CT=2, Period=5
		{2, 1, 0, 3, 0, 3},  // Task 2: CT=1, Period=3
		{3, 1, 0, 7, 0, 7}   // Task 3: CT=1, Period=7
	};

	schedule_rms(arr, 3, 30);
	return 0;
}
