/*
 * Producer - Consumer
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <setjmp.h>

#define MAX 5
jmp_buf jbuf;
int ch;

int
	buffer[MAX],
	in = 0,
	out = 0,
	count = 0,
	full = 0,
	empty = MAX,
	mutex = 1;

void
wait(int *s) {
	if (
		(ch == 0 && empty == 0)	
		|| (ch == 1 && full == 0)
	) {
		longjmp(jbuf, 0);
	}
	while ((*s) <= 0){}
	(*s)--;
}

void
signal(int *s) {
	(*s)++;
}

void
produce() {
	wait(&mutex);
	wait(&empty);

	buffer[in] = count++;
	printf("Produced %d at %d.\n", buffer[in], in);
	in = (1 + in) % MAX;

	signal(&full);
	signal(&mutex);
}

void
consume() {
	wait(&mutex);
	wait(&full);

	printf("Consumed %d at %d.\n", buffer[out], out);
	out = (1 + out) % MAX;

	signal(&empty);
	signal(&mutex);
}

int
main() {
	srand(time(NULL));
	for(;;) {
		setjmp(jbuf);
		sleep(1);
		ch = rand() % 2;
		switch (ch) {
			case 0:
				produce();
				break;
			case 1:
				consume();
				break;
		}
	}
	return 0;
}
