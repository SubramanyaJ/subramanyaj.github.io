/*
 * Producer - Consumer
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX 5

int
	phi[MAX],
	cho[MAX],
	mutex = 1;

void
wait(int *s) {
	while ((*s) <= 0){}
	(*s)--;
}

void
signal(int *s) {
	(*s)++;
}

void
pickup(int p) {
	wait(&mutex);
	if(
		!phi[p]
		&& !cho[p]
		&& !cho[(1 + p) % MAX]
	) {
		phi[p] = cho[p] = cho[(1 + p) % MAX] = 1;
		printf("Philosopher %d started eating.\n", p);	
	} else {
		printf("Philosopher %d cannot start eating.\n", p);
	}
	signal(&mutex);
}

void
putdown(int p) {
	wait(&mutex);
	if(
		phi[p]
		&& cho[p]
		&& cho[(1 + p) % MAX]
	) {
		phi[p] = cho[p] = cho[(1 + p) % MAX] = 0;
		printf("Philosopher %d stopped eating.\n", p);	
	} else {
		printf("Philosopher %d was not eating.\n", p);
	}
	signal(&mutex);
}

int
main() {
	int pc, bc;
	for(;;) {
		sleep(1);
		pc = rand() % MAX;
		bc = rand() % 2;
		(bc == 0) ? putdown(pc) : pickup(pc);
	}
	return 0;
}
