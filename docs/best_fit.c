/* Best Fit */

#include <stdio.h>

void
best_fit(int *blocks, int b, int *processes, int p) {

	int allocation[p];
	for(int i = 0; i < p; i++) {
		allocation[i] = -1;
	}
	for(int i = 0; i < p; i++) {
		int idx = -1;
		for(int j = 0; j < b; j++) {
			if(
				blocks[j] >= processes[i]
				&& (idx == -1
					|| blocks[idx] > blocks[j])
			) {
				idx = j;
			}
		}
		if(idx != -1) {
			allocation[i] = idx;
			blocks[idx] -= processes[i];
		}
	}

	printf("P.num\tP.size\tB.num\tB.size\n");	
	for(int i = 0; i < p; i++) {
		if(allocation[i] != -1) {
			printf("%d\t%d\t%d\t%d\n", i+1, processes[i], allocation[i] + 1, blocks[allocation[i]]);	
		} else {
			printf("%d\t%d\tNot Allocated\n", i+1, processes[i]);
		}		
	}
}

int
main() {
	int b, p;
	printf("Enter number of blocks and processes : ");
	scanf("%d %d", &b, &p);
	int blocks[b], processes[p];

	printf("Enter the size of blocks : \n");
	for(int i = 0; i < b; i++) {
		printf("Block [%d] : ", i);	
		scanf("%d", &blocks[i]);
	}

	printf("Enter the size of processes : \n");
	for(int i = 0; i < p; i++) {
		printf("Process [%d] : ", i);	
		scanf("%d", &processes[i]);
	}
	best_fit(blocks, b, processes, p);

	return 0;
}
