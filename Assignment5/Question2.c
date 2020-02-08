#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    scanf("%d", &n);

    int ar[n];
    for(int x = 0; x < n; x++) {
    	scanf("%d", &ar[x]);
    }
    long long int ans = 0;
    for(int x = 1; x < 19; x++) {
    	int r = 1 << (x-1);
    	int c = 0;
    	for (int y = 0; y < n; y++) {
	    	if((ar[y] & r) == 0) {
	    		c++;
	    	}
	    }
	    ans = ans + (c * (n-c));
    }

    printf("%lld\n", 2*ans);
}