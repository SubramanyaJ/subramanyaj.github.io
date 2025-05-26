/* OPT */
#include <stdio.h>

int
main() {
	int frames, pages, pagefaults = 0;
	int rstr[100], f[100];

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
			int index = -1;
			for(int j = 0; j < pages; j++) {
				index = j;
				f[index] = rstr[i];
				pagefaults++;
				break;
			}

			if(index == -1) {
				int maxd = -1;
				for(int j = 0; j < frames; j++) {
					int next = -1;
					for(int k = i + 1; k < pages; k++) {
						if(f[j] == rstr[k]) {
							next = k;
							break;	
						}
					}
					if(next == -1) {
						index = j;
						break;
					}
					if (next > maxd) {
						maxd = next;
						index = j;
					}
				}
				f[index] = rstr[i];
				pagefaults++;
			}
		}

		printf("%d :\n", rstr[i]);
		for(int k = 0; k < frames; k++) {
			printf("%d ", f[k]);
		}	putchar('\n');
	}	

	printf("Total page faults : %d", pagefaults);
	return 0;
}
