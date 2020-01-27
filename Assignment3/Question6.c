#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
	int n;
	scanf("%d", &n);
	int * ar[n];

	for (int x = 0; x < n; x++) {
		ar[x] = (int *)(calloc(1, sizeof(int)));
	}

	int size[n];
	for (int x = 0; x < n; x++) {
		size[x] = 1;
	}

	for (int x = 0; x < n-1; x++) {
		int a, b;
		scanf("%d%d", &a, &b);

		ar[a][size[a]-1] = b;
		ar[b][size[b]-1] = a;

		ar[a] = realloc(ar[a], size[a]+1);
		ar[b] = realloc(ar[b], size[b]+1);
		size[a]++;
		size[b]++;
	}

	int level[n];
	for(int x = 0; x < n; x++) {
		level[x] = -1;
		// printf("%d ", size[x]);
	}
	// printf("\n");
	int stack[2*n];
	int i = 0;
	int j = 0;
	stack[j] = 0;
	j++;
	level[0] = 0;
	while(i<j) {
		int r = stack[i];
		i++;
		for (int x = 0; x < size[r]-1; x++) {
			if(level[ar[r][x]] == -1) {
				level[ar[r][x]] = level[r] + 1;
				stack[j] = ar[r][x];
				j++;
			}
		}
	}
	int min = 10000;
	for (int x = 0; x < n; x++) {
		if(size[x] == 2) {
			min = level[x] < min ? level[x] : min;
		}
		// printf("%d ", level[x]);
	}
	int count = 0;
	int ans = -1;
	for (int x = 0; x < n; x++) {
		if(level[x] == min  && size[x] == 2) {
			count++;
			if(count == 1)
				ans = x;
		}
	}
	printf("%d\n%d\n", count, ans);
}