#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main() {

	int n;
	scanf("%d", &n);
	int * ptr[n];
	for (int x = 0; x < n; x++) {
		ptr[x] = (int *)(calloc(1, sizeof(int)));
	}

	int size[n];
	for (int x = 0; x < n; x++) {
		size[x] = 1;
	}

	for (int x = 1; x <= n-1; x++) {
		int a;
		scanf("%d", &a);

		ptr[a][size[a]-1] = x;
		// ptr[b][size[b]-1] = a;

		ptr[a] = realloc(ptr[a], size[a]+1);
		// ptr[b] = realloc(ptr[b], size[b]+1);
		size[a]++;
		// size[b]++;
	}

	int stack[2*n];
	int i = 0;
	int j = 0;
	stack[j] = 0;
	j++;
	int level[n];
	for (int x=0; x<n; x++) 
		level[x] = -1;
	level[0] = 0; 
	while(i<j) {
		int r = stack[i];
		i++;
		for (int x = 0; x < size[r]; x++) {
			if (level[ptr[r][x]] == -1) {
				stack[j] = ptr[r][x];
				j++;
				level[ptr[r][x]] = level[r] + 1;
			}
		}
	}
	int l;
	scanf("%d",&l);
	for (int x = 0; x < n; x++) {
		if(level[x] == l)
			printf("%d ",x);
	}

	// for (int x = 0; x < n; x++) {
	// 	for (int y = 0; y < size[x]-1; y++) {
	// 		printf("%d ", ptr[x][y]);
	// 	}
		// printf("\n");
	// }
	printf("\n");
}