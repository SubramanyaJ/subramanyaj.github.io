/* FIFO */
#include <stdio.h>

int
main() {
	int frames, pages, pagefaults = 0;
	int rstr[100], f[100];

	int current = 0;
	printf("Enter the number of pages : ");
	scanf("%d", &pages);
	printf("Enter the number of frames : ");
	scanf("%d", &frames);

	for(int i = 0; i < frames; i++) {
		f[i] = -1;
	}

	printf("Enter the reference string : ");
	for(int i = 0; i < pages; i++) {
		scanf("%d", &rstr[i]);
	}

	for(int i = 0; i < pages; i++) {
		int found = 0;
		for(int j = 0; j < frames; j++) {
			if(rstr[i] == f[j]) {
				found = 1;
				break;
			}
		}
		if(!found) {
			f[current] = rstr[i];
			current = (1 + current) % frames;
			pagefaults++;
		}
		printf("%d :\n", rstr[i]);
		for(int k = 0; k < frames; k++) {
			printf("%d ", f[k]);
		}	putchar('\n');
	}	

	printf("Total page faults : %d", pagefaults);
	return 0;
}
