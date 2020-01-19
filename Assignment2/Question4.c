#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int dsu[501];
void initialize() {
	for (int x = 0; x < 501; x++) {
		dsu[x] = x;
	}
}

int root(int n) {
	while (dsu[n] != n) {
		dsu[n] = dsu[dsu[n]];
		n = dsu[n];
	}
	return n;
}

void unione(int a, int b) {
	int root_a = root(a);
	int root_b = root(b);
	dsu[root_b] = dsu[root_a];
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	initialize();
	for (int x=0; x<m; x++) {
		int a, b;
		scanf("%d%d", &a, &b);
		unione(a,b);
	}

	// for (int x = 0; x <= n; x++) {
	// 	printf("%d ", dsu[x]);
	// }

	int ar[n+1];
	for (int x = 0; x <= n; x++) {
		ar[x] = 0;
	}

	for (int x = 1; x <= n; x++) {
		ar[root(x)]++;
	}

	int max = 0;
	int i = 0;
	for (int x = 1; x <= n; x++) {
		if (ar[x] > max) {
			i = x;
			max = ar[x];
		}
	}
	printf("%d\n",n - max);
	for (int x = 1; x <= n; x++) {
		if (root(x) != i) {
			printf("%d ",x);
		}
	}
	printf("\n");
}