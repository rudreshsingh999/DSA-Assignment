#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int ar[n+1];

	for(int x = 0; x <= n; x++) {
		ar[x] = x;
	}

	for (int x = 0; x < m; x++) {
		int a, b;
		scanf("%d%d", &a, &b);

		for (int y = 1; y <= n; y++) {
			if(ar[y] == ar[b]) {
				ar[y] = ar[a];
			}
		}
	}
	int f = 0;
	for (int x = 2; x <= n; x++) {
		if(ar[x] != ar[1]) {
			f = 1;
			break;
		}
	}

	if(f == 0)
		printf("%d\n", ar[1]);
	else
		printf("BAD LUCK");
}