/* Deadlocl avoidance */

#include <stdio.h>
#include <string.h>

int
main() {
	int p, r;
	printf("Enter the number of processes and resources : ");	
	scanf("%d %d", &p, &r);

	int 
		alloc[p][r],
		max[p][r],
		need[p][r],
		avai[r],
		finished[p],
		safe[p],
		count = 0;

	memset(avai, 0x00, sizeof(avai));
	memset(finished, 0x00, sizeof(finished));

	printf("Enter the allocation matrix : \n");
	for(int i = 0; i < p; i++) {
		for(int j = 0; j < r; j++) {
			scanf("%d", &alloc[i][j]);	
		}		
	}

	printf("Enter the max matrix : \n");
	for(int i = 0; i < p; i++) {
		for(int j = 0; j < r; j++) {
			scanf("%d", &max[i][j]);	
			need[i][j] = max[i][j] - alloc[i][j];
		}		
	}

	printf("Enter the available resources :\n");
	for(int i = 0; i < r; i++) {
		scanf("%d", &avai[i]);
	}

	int i, j, k;
	while(count < p) {
		int found = 0;
		for(i = 0; i < p; i++) {
			if(!finished[i]) {
				for(j = 0; j < r; j++) {
					if(need[i][j] > avai[j]) {break;}
				}
				if(j == r) {
					for(k = 0; k < r; k++) {
						avai[k] += alloc[i][k];
					}
					safe[count++] = i;
					finished[i] = 1;
					found = 1;
				}
			}
		}
		if(!found) {
			return 1;
		}
	}
	printf("Safe.\n");
	for(int i = 0; i < p; i++) {
		printf("%d ", safe[i]);		
	}	putchar('\n');
	return 0;
}
