#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
	int n,m;
	scanf("%d%d", &n, &m);
	int * ar[n];

	for (int x = 0; x < n; x++) {
		ar[x] = (int *)(calloc(1, sizeof(int)));
	}

	int size[n];
	for (int x = 0; x < n; x++) {
		size[x] = 1;
	}

	for (int x = 0; x < m; x++) {
		int a, b;
		scanf("%d%d", &a, &b);

		ar[a][size[a]-1] = b;
		ar[b][size[b]-1] = a;

		ar[a] = realloc(ar[a], size[a]+1);
		ar[b] = realloc(ar[b], size[b]+1);
		
		size[a]++;
		size[b]++;
	}
	int r;
	scanf("%d", &r);

	int min = 100000;
	int ans = -1;
	for (int x = 0; x < n; x++) {
		if(x == r)
			continue;
		int stack[2*n];
		int i = 0;
		int j = 0;
		int vis[n];
		for (int y = 0; y < n; y++) {
			vis[y] = 0;
		}
		stack[j] = r;
		j++;
		vis[r] = 1;
		vis[x] = 1;
		int c = 0;
		while(i < j) {
			int a = stack[i];
			c++;
			i++;
			for (int y = 0; y < size[a]-1; y++) {
				if(vis[ar[a][y]] == 0) {
					vis[ar[a][y]] = 1;
					stack[j] = ar[a][y];
					j++;
				}
			}
		}

		if(c < min) {
			min = c;
			ans = x;
		}
	}
	printf("%d %d\n", min, ans);
}