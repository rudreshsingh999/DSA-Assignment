#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define M 1000000

int dp[M+1];
int a,b,c,d,e,f;
void jumps(int n, int step) {
	if (n <= M && dp[n]>step) {
		dp[n] = step;
		jumps(a*n + b, step+1);
		jumps(c*n + d, step+1);
		jumps(e*n + f, step+1);
	}
}

int main() {
	// int a,b,c,d,e,f;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	// printf("%d %d %d %d %d %d", a, b, c, d, e, f);
	for (int x=0; x<=M; x++) {
		dp[x] = 9999999;
	}
	// printf("%d", dp[5]);
	int n;
	scanf("%d", &n);
	// printf("%d\n", n);
	int ar[n];
	for (int x=0; x<n; x++) {
		scanf("%d",&ar[x]);
	}
	jumps(0, 0);
	for (int x=0; x<n; x++) {
		if (dp[ar[x]] == 9999999) {
			printf("-1\n");
		}
		else
			printf("%d\n",dp[ar[x]]);
	}
	return 0;
}