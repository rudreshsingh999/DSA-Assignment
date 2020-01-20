#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define M 1000000

// int dp[M+1];
// int a,b,c,d,e,f;
// void jumps(int n, int step) {
// 	if (n <= M && dp[n]>step) {
// 		dp[n] = step;
// 		jumps(a*n + b, step+1);
// 		jumps(c*n + d, step+1);
// 		jumps(e*n + f, step+1);
// 	}
// }

int main() {
	int a,b,c,d,e,f;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	// printf("%d %d %d %d %d %d", a, b, c, d, e, f);
	int dp[M+1];
	for (int x=0; x<=M; x++) {
		dp[x] = 999999;
	}
	// printf("%d", dp[5]);
	
	dp[0] = 0;
	for (int x=0; x<=M; x++) {
		if (dp[x] != 999999) {
			if(a*x + b <= M) 
				dp[a*x + b] = dp[a*x + b] > (dp[x] + 1) ? (dp[x] + 1) : dp[a*x + b];
			if(c*x + d <= M) 
				dp[c*x + d] = dp[c*x + d] > (dp[x] + 1) ? (dp[x] + 1) : dp[c*x + d];
			if(e*x + f <= M) 
				dp[e*x + f] = dp[e*x + f] > (dp[x] + 1) ? (dp[x] + 1) : dp[e*x + f];
		}
	}

	int n;
	scanf("%d", &n);
	int ar[n];
	for (int x = 0; x < n; x++) {
		scanf("%d",&ar[x]);
	}


	for (int x = 0; x < n; x++) {
		printf("%d\n", dp[ar[x]]);
	}
	return 0;
}