#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	int ar[n+1];
	for(int x = 0; x < n; x++) {
		ar[x] = 0;
	}

	for(int x = 0; x < m; x++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		ar[a] = ar[a] + c;
		ar[b+1] = ar[b+1] - c;
	}	


	int ans[n];
	ans[0] = ar[0];
	for(int x = 1; x < n; x++) {
		ans[x] = ar[x] + ans[x-1];
	}

	for (int x = 0; x < n; x++) {
		printf("%d ", ans[x]);
	}
	printf("\n");
}